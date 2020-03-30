#include <stdio.h>
char c;
struct process{
    int arrival_time,burst_time,firstt,name,status,burst_left,compt;
    int waiting_time,turnaround_t;
}*run=NULL;
int n,timequant=10,px=0;
struct exec{
    struct process *q;
    struct exec *next;
}*start=NULL,*end,*cn;

		
int main()
{     printf("\nNOTE:  The arrival time must not start with 0 as time array in the program starts with 1\n ");
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
                    else
                    {
                        while(x->next!=NULL && x->next->q->burst_left < cn->q->burst_left)
                        {
                            x=x->next;
                        }
                        cn->next=x->next;
                        x->next=cn;
                    }
                }
                px--;
            }
        }
        }
        if(px==0 && y==1)
        {
            for(int i=0;i<n;i++)
            {
                if(p[i].arrival_time<=3 && p[i].status==0)                                                //in the queue
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
                        else
                        {
                            while(x->next!=NULL && x->next->q->burst_left < cn->q->burst_left)
                            {
                                x=x->next;
                            }
                            cn->next=x->next;
                            x->next=cn;
                        }
                    }
                }
            }
            y--;
            
    printf("\n\n");
	
	printf("===================================\n");
	printf("\tProcess execution order: \n");
	printf("===================================\n\n");
        }
        if(run==NULL)   //running of process
        {
            if(start!=NULL)
            {
                run=start->q;
                start=start->next;
                if(run->firstt==-1)
                {
                    run->firstt=time;
                }
                if(run->burst_left<=timequant)
                {
                    printf(" %c ",run->name);
                    time=time+run->burst_left;
                    run->burst_left=0;
                    run->compt=time;
                    run->status=2;
                    processleft--;
                }
                else if(run->burst_left>timequant)
                {
                   	printf(" %c ",run->name);
                    time=time+timequant;
                    run->burst_left=run->burst_left-timequant;
                    run->compt=time;
                    if(start==NULL)
                    {
                        cn=new exec;
                        cn->q=run;
                        cn->next=NULL;
                        end=cn;
                        start=cn;
                    }
                    else
                    {
                        cn=new exec;
                        cn->q=run;
                        exec *x;
                        x=start;
                        if((start->q->burst_left)>(cn->q->burst_left))
                        {
                            cn->next=start;
                            start=cn;
                        }
                        else
                        {
                            while(x->next!=NULL && x->next->q->burst_left < cn->q->burst_left)
                            {
                                x=x->next;
                            }
                            cn->next=x->next;
                            x->next=cn;
                        }
                    }
                }
            }
            run=NULL;
        }
    }

    float avgwaitt=0,avgtat=0;
    for(int i=0;i<n;i++)
    {
        p[i].turnaround_t=((p[i].compt)-(p[i].arrival_time));
        p[i].waiting_time=((p[i].turnaround_t)-(p[i].burst_time));
        avgwaitt=avgwaitt+p[i].waiting_time;
        avgtat=avgtat+p[i].turnaround_t;
    }
    avgwaitt=avgwaitt/n;
    avgtat=avgtat/n;
    
   	
    printf("\nAverage  waiting time = %f ",avgwaitt);
    printf("\nAverage Turn Around Time = %f \n",avgtat);
}
