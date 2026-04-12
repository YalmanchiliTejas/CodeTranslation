#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=3e3+55;
ll dp[N][N];
ll a[N];
int n;

ll bt(int l , int r , int t)
{
	if(l==r)
		return t*a[l];
	ll &ret=dp[l][r];
	if(ret!=-1)
		return ret;
	if(t==-1)
	ret=min(bt(l+1,r,1)-a[l],bt(l,r-1,1)-a[r]);
	else
	ret=max(bt(l+1,r,-1)+a[l],bt(l,r-1,-1)+a[r]);
	return ret;
}
	
	

int main()
{
	memset(dp,-1,sizeof dp);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<bt(0,n-1,+1)<<endl;
	return 0;
}
