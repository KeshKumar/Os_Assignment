#include<stdio.h>
struct requirement
{
	boolean pen= 0;
	boolean paper = 0;
	boolean question_paper=0;
	boolean all_three=0;
};
int main()
{
	struct reqirement student[3];
	s[0].pen=1;				
	s[1].paper=1;				
	s[2].question_paper=1;				
	while(s[0].all_three==0||s[1].all_three==0||s[2].all_three==0)
	{
		char ch1,ch2;
		printf("Menu: \n1.pen\n2.paper\n3.question paper\n Enter the two things which is to be placed on the shared table");
		scanf("%c%c",&ch1,&ch2);
		if(ch1=='1' && ch2=='2' && s[2].all_three==0)
		{
			s[2].all_three=1;
			printf("Student three has completed the task");
		}
		if(ch1=='2' && ch2=='3's[0].all_three==0)
		{
			s[0].all_three=1;
			printf("Student one has completed the task");
		}
		if(ch1=='1' && ch2=='3's[1].all_three==0)
		{
			s[1].all_three=1;
			printf("Student second has completed the task");
		}
	}
	printf("All students completed the task");
	return 0;
}
