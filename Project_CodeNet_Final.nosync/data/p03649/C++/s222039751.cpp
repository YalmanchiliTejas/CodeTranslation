#include <bits/stdc++.h>

using namespace std;

const int N=55;

int n;
long long arr[N],cur[N];

bool can(long long x)
{
	for(int i=0;i<n;i++)
	{
		cur[i]=arr[i]+x;
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		long long dif=cur[i]-(n-1);
		ans+=(dif+n)/(n+1);
	}
	return ans<=x;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	long long st=0,en=(1LL<<60),ans=(1LL<<60);
	while(st<=en)
	{
		long long mid=st+(en-st)/2;
		if(can(mid))
		{
			ans=mid; en=mid-1;
		}
		else st=mid+1;
	}
	for(long long curr=max(ans-(long long)1e5,0LL);curr<=ans;curr++)
	{
		if(can(curr))
		{
			ans=curr;
			break;
		}
	}
	cout << ans << endl;
}