#include<stdio.h>

int main()
{
    int n, i, j, temp, temp2, t=0;
    float avgWaitTime=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n], wt[n], tat[n], p[n];
    float priority[n], totalPriority=0;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time and estimated run time of process %d: ",i+1);
        scanf("%d%d",&bt[i],&temp);
        p[i]=i+1;
        priority[i]=1;
        wt[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                temp2=p[i];
                bt[i]=bt[j];
                p[i]=p[j];
                bt[j]=temp;
                p[j]=temp2;
            }
        }
    }
    printf("\nGantt Chart:\n");
    for(i=0;i<n;i++)
    {
        printf("|P%d|",p[i]);
    }
    printf("\n0");
    for(i=0;i<n;i++)
    {
        wt[i]=t;
        totalPriority+=priority[i];
        t+=bt[i];
        tat[i]=t;
        priority[i]=1.0+(float)wt[i]/(float)tat[i];
        if(i<n-1)
        {
            printf(" %d |P%d|",t,p[i]);
        }
        else
        {
            printf(" %d",t);
        }
    }
    avgWaitTime=(float)totalPriority/(float)n;
    printf("\n\nPriority values after each unit of time:\n");
    printf("\n  Time  | Priority values ");
    t=0;
    while(t<tat[n-1])
    {
        printf("\n   %d    |   ",t);
        for(i=0;i<n;i++)
        {
            if(t>=wt[i] && t<tat[i])
            {
                printf("%.2f  ",priority[i]);
            }
        }
        t++;
    }
    printf("\n\nAverage waiting time: %.2f",avgWaitTime);
    printf("\n\nProcess    Burst Time    Waiting Time    Turnaround Time   Priority");
    for(i=0;i<n;i++)
    {
        printf("\n  P%d            %d                %d                  %d            %.2f",p[i],bt[i],wt[i],tat[i]-bt[i],priority[i]);
    }
    printf("\n");
    return 0;
}
