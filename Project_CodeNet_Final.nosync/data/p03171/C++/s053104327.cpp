#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll n;
ll dp[3005][3005][2];
ll a[3005];
ll rec(int l,int r, int p)
{
	if(l>r)
		return 0;
	ll & res=dp[l][r][p];
	if(res!=-1)
		return res;
	if(p==0)
	res=max(a[l]+rec(l+1,r,1-p),a[r]+rec(l,r-1,1-p));
else
	res=min(rec(l+1,r,1-p)-a[l],rec(l,r-1,1-p)-a[r]);
return res;
}
 
int main()
{
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,n-1,0);
	

	
	
	
	
 
	return 0;
}