#include <stdio.h>
int main()
{
	int i,n,k,bt[10],wt[20],tat[20],p[20],temp;
	float wtavg,tatavg;
	printf("\n Enter number of Processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("Enter Burst Time for %d--",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(bt[i]>bt[k])
	{
		//sorting in ascending order
		temp=bt[i];
		bt[i]=bt[k];
		bt[k]=temp;
		
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	}
	//assigning waiting time and turnaroundtime
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++)
	{
		//calculating waiting and turnaround time
		wt[i]=wt[i-1] + bt[i-1];
		tat[i]=tat[i-1] + bt[i];
		wtavg=wtavg + wt[i];
		tatavg=tatavg + tat[i];
	}
	printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++)
		printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
	printf("\nAverage Waiting Time -- %f", wtavg/n);
	printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
