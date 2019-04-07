#include <iostream>
#include <string.h>
using namespace std;
typedef struct proccess
{
	int at,bt,ct,ta,wt,btt,pr;
	string pro_id;
	/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}schedule;
int main()
{
	schedule pro[10];
	int n,i,j,pcom;
    cout<<"Priority Preemptive Scheduling......"<<endl;
    cout<<"Note : Less is the priority number more is the priority"<<endl;
	cout<<"Enter the number of process:";
	cin>>n;
	cout<<"Enter Details of the process:::";
	i=0;
	while(i<n)
	{
	    cout<<"Enter the proces id"<<endl;
		cin>>pro[i].pro_id;
		cout<<"Enter the Arrival Time"<<endl;
		cin>>pro[i].at;
		cout<<"Enter the Burst Time"<<endl;
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
		cout<<"Enter the priority"<<endl;
		cin>>pro[i].pr;
		i++;
	}
	struct proccess temp;
    int m,r;
    for(m=0;m<n-1;m++)
    for(r=m+1;r<n;r++)
    {
    if(pro[m].at>pro[r].at)
    {
    temp=pro[m];
    pro[m]=pro[r];
    pro[r]=temp;
    }
    }
	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}
    struct proccess temp2;
    int i1,i2;
    for(i1=0;i1<j-1;i1++)
    for(i2=i1+1;i2<j;i2++)
    {
    if(pro[i1].pr<pro[i2].pr)
    {
    temp2=pro[i1];
    pro[i1]=pro[i2];
    pro[i2]=temp2;
    }
    }


		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)
			i+=pro[j].at-i;
			pro[j].ct=i+1;
			pro[j].bt--;
		}

		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}

	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;
		cout<<"P.ID\t"<<"Arrival Time  "<<"Burst Time "<<"Complettion Time"<<"Turn Around "<<"Waiting Time"<<"Priority";
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}
	float avg_wt,avg_tat;
	int twt=0,tat=0;
    for(int l=0;l<n;l++)
    {
        twt=twt+pro[l].wt;
        tat=tat+pro[l].ta;
    }
    cout<<twt<<endl;
    cout<<tat<<endl;
    cout<<n;
    avg_wt=(float)twt/n;
    avg_tat=(float)tat/n;
    cout<<"Average Waiting time = "<<avg_wt<<endl;
    cout<<"Average Turn Around Time =  "<<avg_tat<<endl;
	return 0;
}

