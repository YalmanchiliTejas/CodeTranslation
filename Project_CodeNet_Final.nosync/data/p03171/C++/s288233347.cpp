#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[3001][3001];
int main()
{
	ll n,i,j;
	cin >> n;
	ll a[n];
	deque<ll>dq;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		dq.push_back(a[i]);
	}
	ll start,end;
	for(start=n-1;start>=0;start--)
	{
		for(end=start;end<n;end++)
			dp[start][end]=max(a[start]-dp[start+1][end],a[end]-dp[start][end-1]);
			
	}
	cout<<dp[0][n-1]<<"\n";
}