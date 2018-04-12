#include<stdio.h>
#include<stdbool.h>
struct requirement
{
 	boolean pen ;
	boolean paper ;
	boolean question_paper ;
	boolean all_three ;
};
int main()
{
	int n=3;
	struct reqirement s[n];
	s[0].pen=true;		
	s[0].paper = false;
	s[0].question_paper = false;
	s[1].pen=false;		
	s[1].paper = true;
	s[1].question_paper = false;
	s[2].pen=false;		
	s[2].paper = false;
	s[2].question_paper = true;	
	while(s[0].all_three==false||s[1].all_three==false||s[2].all_three==false)
	{
		char ch1,ch2;
		printf("Menu: \n1.pen\n2.paper\n3.question paper\n Enter the two things which is to be placed on the shared table");
		scanf("%c%c",&ch1,&ch2);
		if(ch1=='1' && ch2=='2' && s[2].all_three==false)
		{
			s[2].all_three=true ;
			printf("Student three has completed the task");
		}
		if(ch1=='2' && ch2=='3' && s[0].all_three==false)
		{
			s[0].all_three=true;
			printf("Student one has completed the task");
		}
		if(ch1=='1' && ch2=='3' && s[1].all_three==false)
		{
			s[1].all_three=true;
			printf("Student second has completed the task");
		}
	}
	printf("All students completed the task");
	return 0;
}
