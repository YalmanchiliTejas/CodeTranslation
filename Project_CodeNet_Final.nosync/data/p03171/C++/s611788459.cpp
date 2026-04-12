#include<bits/stdc++.h>
#define ll long long 
#define ld long double 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define BOOST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define sl(a) a.size()
#define mod 1000000007 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define MAX 10000003
using namespace std;
ll dp[5005][5005];
ll count(ll arr[], ll i, ll j)
{
    if(i>j) return 0;
    if(i==j) return dp[i][j]=arr[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(arr[i]-count(arr,i+1,j),arr[j]-count(arr,i,j-1));
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    ll n;  cin>>n;
    ll arr[n];
    rep(i,0,n)  cin>>arr[i];
    cout<<count(arr,0,n-1);
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
    #endif
    BOOST
    int T=1;  //cin>>T;
    while(T--) solve();
    return 0;
}
