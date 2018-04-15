#include <stdio.h>


typedef struct Processes {
	int arrival_time;
	int burst_time;
	int p_no;
} Process;


int main() {
	int n, i, j, tq = 3, curr_time = 0;
	int rear = -1, front = 0;
	short error_flag = 0, processed = 0, insert_last_p_no = -1, can_insert, swapped;
	
	do {
		if (error_flag == 1)
			fprintf(stderr, "\nNumber of processes should be greater than 1.\n");

		printf("Enter the number of processes: ");
		scanf("%d", &n);
		
		error_flag = 1;
	} while (n < 1);
	
	error_flag = 0;
	
	Process * queue[9999];
	Process p[n];
	
	for (i = 0; i < n; ++i) {
		printf("Enter arrival time of process %d: ", i);
		scanf("%d", &p[i].arrival_time);
		
		printf("Enter burst time of process %d: ", i);
		scanf("%d", &p[i].burst_time);
		printf("\n");
		
		p[i].p_no = i+1;
	}
	
	for (i = 0; i < n-1; ++i) {
		swapped = 0;
		for (j = 0; j < n-i-1; ++j) {
			if (p[j].burst_time > p[j+1].burst_time) {
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				
				swapped = 1;
			}
		}
		
		if (swapped == 0)
			break;
	}
	
	for (i = 0; i < n; ++i) {
		printf("Process %d\n", p[i].p_no);
	}
	printf("\n\n");
	
	
	while (1) {
		for (i = 0; i < n; ++i) {
			can_insert = 1;
			if (p[i].arrival_time <= curr_time && p[i].burst_time > 0 && insert_last_p_no != p[i].p_no) {
				for (j = front; j <= rear; ++j) {
					if (p[i].p_no == p[j].p_no) {
						can_insert = 0;
						break;
					}
				}
				if (can_insert != 0)
					queue[++rear] = &p[i];
			}
		}
		
		if (insert_last_p_no > 0) {
			queue[++rear] = &p[insert_last_p_no];
		}
		
		printf("Elements is queue: ");
		for (i = 0; i <= rear; ++i) {
			printf("%d ", queue[i]->p_no);
		}
		printf("\n");
		
		if (rear == -1) {
			printf("CPU idle for 1 second.\n");
			curr_time += 1;
		}
		else {
			for (i = front; i <= rear; ++i) {
				
				if (queue[i]->burst_time > tq) {
					queue[i]->burst_time -= tq;
					curr_time += tq;
					insert_last_p_no = queue[i]->p_no;
					printf("Process number %d excuted till %d seconds.\n", queue[i]->p_no, curr_time);
				}
				else if (queue[i]->burst_time > 0) {
					curr_time += queue[i]->burst_time;
					printf("Process number %d excuted till %d seconds.\n", queue[i]->p_no, curr_time);
					queue[i]->burst_time = 0;
					
					++processed;
				}
			
				front += 1;
			}
		}
		
		sleep(2);
		if (processed == n)
			break;
	}
	
	printf("\n\nTotal time taken: %d.", curr_time);
	
	return 0;
}
