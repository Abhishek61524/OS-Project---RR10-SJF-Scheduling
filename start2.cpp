#include <stdio.h>
char c;
struct process{
    int arrival_time,burst_time,firstt,name,status,burst_left,compt;
    int waiting_time,turnaround_t;
}*run=NULL;
    int n,timequant=10,px=0;

  int main()
{
    printf("\nEnter No of processes :");
    scanf("%d",&n);
    int processleft=n; //process left
    struct process p[n];
    for(int i=0,c='A';i<n;i++,c++)
 	{	
		p[i].name=c;
 		printf("\nEnter the arrival_timeival time and burst_time time of process %c: ",p[i].name);
 		scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].burst_left=p[i].burst_time;
       // p[i].i=i+1;
        p[i].status=0;
        p[i].firstt=-1;
        if(p[i].arrival_time>3)
            px++;
    }
   
    struct exec
	{
    struct process *q;
    struct exec *next;
     }*start=NULL,*end,*cn;
    int time=4,y=1;
    while(processleft!=0)
    {
        if(px!=0)
        {
        for(int i=0;i<n;i++)
        {
            if(p[i].arrival_time>3 && p[i].arrival_time<=time && p[i].status==0)                                                //in the queue
            {
                if(start==NULL)
                {
                    p[i].status=1;
                    cn=new exec;
                    cn->q=&p[i];
                    cn->next=NULL;
                    end=cn;
                    start=cn;
                }
                else{
                    p[i].status=1;
                    cn=new exec;
                    cn->q=&p[i];
                    exec *x;
                    x=start;
                    if((start->q->burst_left)>(cn->q->burst_left))
                    {
                        cn->next=start;
                        start=cn;
                    }
                 }
			}
          }
       }
    float avgwaitt=0,avgtat=0;
   
