include<stdio.h>

void p1();

void p2();

int main()

{

	printf("\n\n\t\t\t\tWELCOME\n\n\t\t\tNON PRE-EMPTIVE SCHECDULING\n\n");

	int c;

	printf("Enter 1 to calculate priority Scheduling using SJF\n");

	printf("Enter 2 to calculate priority Scheduling using Give formula \n");

	scanf("%d",&c);

	switch(c)

	{

		case 1:

			printf("Priority is based on burst time, Shortest job first\n");

			p1();

			break;

		case 2:

				printf("\n\tThis is according to given formula of finding priority\n");

			printf("\n\tpriority = 1 + (waiting time/estimated time)\n\n");

			p2();

		

			break;

		default:

			printf("mrng bro wake up\nInvalid Input\n");

	}

}

void p1()

{

    int bt[50],p[50],wt[50],tat[50],at[50],i,j,k,n,total=0,m,pos=0,temp,temp1,priority[50];

    float avg_wt,avg_tat;

    printf("Enter number of process :");

    scanf("%d",&n);

 

    printf("\nEnter Burst Time :\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&bt[i]);

        p[i]=i+1;           

    }

    printf("\nEnter Arrival Time :\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&at[i]);

        p[i]=i+1;           

    }

    printf("\nEnter priority :\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&priority[i]);

        p[i]=i+1;           

    }

for(i=0;i<n;i++)

{

for(j=0;j<n;j++)

{

if(at[i]<at[j])

{

temp=p[j];

p[j]=p[i];

p[i]=temp;

temp=at[j];

at[j]=at[i];

at[i]=temp;

temp1=bt[j];

bt[j]=bt[i];

bt[i]=temp1;

}

}

}

for(j=0;j<n;j++)

{   pos=pos+bt[j];

   m=bt[k];

for(i=k;i<n;i++)

{ m=priority[k];

if (pos>=at[i])

{

if(priority[i]<m)

{

temp=p[k];

p[k]=p[i];

p[i]=temp;

temp=at[k];

at[k]=at[i];

at[i]=temp;

temp1=bt[k];

bt[k]=bt[i];

bt[i]=temp1;

temp=priority[k];

priority[k]=priority[i];

priority[i]=temp;



}

}

}

k++;

}

 

    wt[0]=0;     

    

    for(i=1;i<n;i++)

    {

        wt[i]=0;

        for(j=0;j<i;j++)

            wt[i]+=bt[j];

 

        total+=wt[i];

    }

 

    avg_wt=(float)total/n; 

    total=0;

 	printf("\n*********************************************************************************\n");

    printf("\nProcess\t    Burst Time\t    \tWaiting Time\tTurnaround Time\tPriority");

    printf("\n*********************************************************************************\n");

	for(i=0;i<n;i++)

    {

        tat[i]=bt[i]+wt[i];

        total+=tat[i];

        printf("\np%d\t\t  %d\t\t    %d\t\t   %d  \t\t%d\t\t",p[i],bt[i],at[50],wt[i],tat[i],priority[i]);

    }

 	printf("\n*********************************************************************************\n");

    avg_tat=(float)total/n;

    printf("\n\nAverage Waiting Time=%f",avg_wt);

    printf("\nAverage Turnaround Time=%f\n",avg_tat);

}



void p2()

{

    int bt[50],p[50],wt[50],tat[50],at[50],i,j,n,total=0,pos,temp,priority[50];

    float avg_wt,avg_tat;

    printf("Enter number of process :");

    scanf("%d",&n);

 

    printf("\nEnter Burst Time :\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&bt[i]);

        p[i]=i+1;           

    }

    printf("\nEnter Arrival Time :\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&at[i]);

        p[i]=i+1;           

    }

 

    for(i=0;i<n;i++)  //main logic

    {

    	priority[i]=1+(wt[i]/bt[i]);

	}

    for(i=0;i<n;i++)

    {

        pos=i;

        for(j=i+1;j<n;j++)

        {

            if(priority[j]<priority[pos])

                pos=j;

        }

 

        temp=bt[i];

       priority[i]=priority[pos];

        priority[pos]=temp;

 

        temp=p[i];

        p[i]=p[pos];

        p[pos]=temp;

    }

 

    wt[0]=0;     

    

    for(i=1;i<n;i++)

    {

        wt[i]=0;

        for(j=0;j<i;j++)

            wt[i]+=bt[j];

 

        total+=wt[i];

    }

 

    avg_wt=(float)total/n; 

    total=0;

    printf("\n*********************************************************************************\n");

    printf("\nProcess\t    Burst Time   \t Waiting Time\tTurnaround Time\t	\n");

    printf("\n*********************************************************************************\n");

    for(i=0;i<n;i++)

    {

        tat[i]=bt[i]+wt[i];

        total+=tat[i];

        printf("\np%d\t\t  %d\t\t    %d\t\t   %d\t\t  \t",p[i],bt[i],at[i],wt[i],tat[i]);

    }

 	printf("\n*********************************************************************************\n");

    avg_tat=(float)total/n;

    printf("\n\nAverage Waiting Time=%f",avg_wt);

    printf("\nAverage Turnaround Time=%f\n",avg_tat);

}
