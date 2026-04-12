#include<bits/stdc++.h>
using namespace std;

long long m;

long long power(long long x, long long y) 
{ 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main()
{
	long long n;
	cin>>n;
	
	long long x;
	cin>>x>>m;
	
	int arr[m+1]={0};
	
	arr[x]=1;
	
	vector<int> ans={-1,x};
	
	long long cycle_start=-1;
	long long cycle_len;
	
	for(int i=2;i<=n;i++)
	{
		long long next_val=power(ans.back(),2);
		ans.push_back(next_val);
		
		if(arr[next_val]==0)
			arr[next_val]=i;
		else
		{
			cycle_start=arr[next_val];
			cycle_len=i-arr[next_val];
			
			break;
		}
	} 
	
	long long sum=0;
	
	if(cycle_start==-1)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=ans[i];	
		}
	}	
	else
	{
		for(int i=1;i<cycle_start;i++)
		{
			sum+=ans[i];
		}
		
		long long rem=(n-cycle_start+1);
		
		long long num_times=rem/cycle_len;
		long long reminder=rem%cycle_len;
		
		long long t_sum=0;
		
		for(int i=cycle_start;i<cycle_start+cycle_len;i++)
		{
			t_sum+=ans[i];	
		}
		
		t_sum*=num_times;
		sum+=t_sum;
		
		for(int i=cycle_start;i<cycle_start+reminder;i++)
		{
			sum+=ans[i];
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}