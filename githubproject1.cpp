#include<iostream>
using namespace std;
int main() 
{
      int at[10], bt[10];//at stands for arrival time and bt stands for burst time
      int i, low, n;
      double wt = 0;//wt=waiting time
	  double ta = 0;//ta=turnaround time
	  double it;//intermediate time
      float avgwt, avgta;//avgwt=average waiting time  avgta=average turnaround time
      cout<<"Enter the Total Number of Processes"<<endl;
      cin>>n; //max no of processes
      cout<<"Enter Details of  Processes"<<endl;
      int temp[10];//temporary variable for storing burst time
      for(i = 0; i < n; i++)
      {
            cout<<"Enter Arrival Time for "<<" process  "<<i<<endl;
            cin>>at[i];//taking user input for arrival time
            cout<<"Enter Burst Time for "<<" process  "<<i<<endl;
            cin>>bt[i];//taking user input for burst time
            temp[i] = bt[i];
      }
      bt[9] = 9999; 
	  int t; //t represents time
      int count=0;
      for(t = 0; count != n; t++)
      {
            low = n-1;
            for(i = 0; i < n; i++)
            {
                  if(at[i] <= t && bt[i] < bt[low] && bt[i] > 0)
                  {
                        low = i;
                  }
            }
            bt[low]--;
            if(bt[low] == 0)
            {
                  count++;
                  end = t + 1;
                  wt = wt + end - at[low] - temp[low];
                  ta = ta + end - at[low];
            }
      }
      avgwt = wt / n; 
      avgta = ta / n;
      cout<<"Average Waiting Time:"<< avgwt<<endl;
      cout<<"Average Turnaround Time:"<< avgta<<endl;;
      return 0;
}
