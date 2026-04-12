#include <bits/stdc++.h>
#define hell 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long int
#define pi 3.1415926536
using namespace std;

ll game(ll str,ll end,vector<ll> &v,vector<vector<ll> > &dp)
{	
	
	if(str>end)
		return 0;
	if(str+1==end||str==end)
		return(dp[str][end]=max(v[str],v[end]));
		
	if(dp[str][end]!=-1)
		return dp[str][end];
		
	if(dp[str+2][end]==-1)
		dp[str+2][end]=game(str+2,end,v,dp);
	
	if(dp[str+1][end-1]==-1)
		dp[str+1][end-1]=game(str+1,end-1,v,dp);
		
	if(dp[str][end-2]==-1)
		dp[str][end-2]=game(str,end-2,v,dp);
		
	dp[str][end]=max(v[str]+min(dp[str+2][end],dp[str+1][end-1]),v[end]+min(dp[str+1][end-1],dp[str][end-2]));
	
	return dp[str][end];
}
void solve()
{ll n,m,x,y,z,d,p=0,b=0,q,l=INT_MAX,k,mini=0,prev;
 cin>>n;
 vector<ll> v(n);
 for(ll i=0;i<n;i++)
 {
 	cin>>v[i];  p+=v[i];
 }
 
 vector<vector<ll> > dp(3005,vector<ll>(3005,-1));//a(3005,vector<ll>(m,0));
 cout<<(2*game(0,n-1,v,dp))-p;
}

int main()
{
  fast
ll t=1;

while(t--)
{solve();
 //cout<<ma<<endl;
}
return 0;}