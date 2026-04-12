#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e9+18
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=105;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
#define ub upper_bound
#define pie 3.14159265359
#define mod 1000000007
ll dp[3005][3005];

ll stones(ll a[],ll sta ,ll end,ll id)
{
   if(sta>=end)
   return 0;	
if(dp[sta][end]!=-1)
	return dp[sta][end];
ll ans=0;
if(id)
 ans=max(a[sta]+stones(a,sta+1,end,0),a[end-1]+stones(a,sta,end-1,0));
else
 ans=min(stones(a,sta+1,end,1),stones(a,sta,end-1,1));
dp[sta][end]=ans;
return ans;
  
}
int main()
{    fastio;
	ll int n,sum=0;
	cin>>n;
	ll int a[n];
	for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   	sum+=a[i];
   }
  memset(dp,-1,sizeof(dp));
ll k=stones(a,0,n,1);
	cout<<2*k-sum;
}