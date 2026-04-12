#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define mod 1000000007
unordered_map<char,vector<string>> adj;
vector<ll> vis(100005,0);
vector<ll> p(100005,0);
ll c[100005];
/*void dfs(ll node,ll len)
{
	if(len==n)
	{
		ans++;
		return;
	}
	for(auto str:adj[node])
		dfs(str[0],len+1);
}*/
int main()
{
 ll n;
 cin>>n;
 ll a[n],dp[n+1];
 dp[n]=0;
 ll i;
 ll sum=0;
 for(i=0;i<n;i++)
   cin>>a[i];
  for(i=n-1;i>=0;i--)
  {
     dp[i]=(dp[i+1]+a[i])%mod;
  }
  for(i=0;i<n;i++)
  {
     sum=(sum+(a[i]*dp[i+1])% mod)% mod;
  }
  cout<<sum;
}