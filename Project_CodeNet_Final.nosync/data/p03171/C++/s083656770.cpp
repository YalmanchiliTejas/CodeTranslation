#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define modd 998244353
#define umap unordered_map<ll,ll>
 ll n;
 ll dp[3001][3001];

 ll funn(ll start,ll end,ll a[]){
  if(start>end)return 0;
  if(dp[start][end]!=1e13)return dp[start][end];
 
     ll chance = (n-1-end)+(start);
     if(chance&1)return dp[start][end]=min(-1*a[end]+funn(start,end-1,a),-1*a[start]+funn(start+1,end,a));
     else return dp[start][end]=max(a[end]+funn(start,end-1,a),a[start]+funn(start+1,end,a));

 }
 
int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
   
    cin>>n;
    ll a[n];
    fori(0,n)cin>>a[i];

    fori(0,3001)
    for (int j = 0; j < 3001; ++j)
    {
      dp[i][j]=1e13;
    }

    
    cout<<funn(0,n-1,a);
 
return 0;
}