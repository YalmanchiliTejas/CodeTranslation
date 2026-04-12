#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bs binary_search
#define pb push_back
#define pp pair<ll,ll>
#define F first 
#define S second 
#define lc "\n"
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
int main() 
{
    fastio
    ll n,i,d; cin>>n; ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll dp[n][n];
	for(i=0;i<n;i++) dp[i][i]=arr[i];
	for(d=1;d<n;d++)
	{
	    for(int i=0;i<n-d;i++)
	    dp[i][i+d]=max(arr[i]-dp[i+1][i+d],arr[i+d]-dp[i][i+d-1]);
	}
	cout<<dp[0][n-1];
    return 0;
}