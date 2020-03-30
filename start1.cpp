#include <stdio.h>
char c;
struct process{
    int arrival_time,burst_time,name,status,burst_left,compt;
    int waiting_time,turnaround_t;
}*run=NULL;
    int n,timequant=10;

  int main()
{
    printf("\nEnter No of processes :");
    scanf("%d",&n);
    int processleft=n; 
    struct process p[n];
    for(int i=0,c='A';i<n;i++,c++)
 	{	
		p[i].name=c;
 		printf("\nEnter the arrival_timeival time and burst_time time of process %c: ",p[i].name);
 		scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].burst_left=p[i].burst_time;
       // p[i].i=i+1;
        p[i].status=0;
        if(p[i].arrival_time>3){
		}
            
    }
   
    
    int idle_time=3;
}
    
