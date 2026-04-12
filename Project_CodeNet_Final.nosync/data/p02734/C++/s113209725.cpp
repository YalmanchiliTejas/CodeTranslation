#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define all(x) x.begin(),x.end()
#define bs binary_search
#define gcd(a,b) __gcd(a,b)
#define PI 3.1415926535897932384626
#define lp lower_bound
#define up upper_bound
#define minimum(a)	*min_element(a.begin(), a.end())
#define maximum(a)	*max_element(a.begin(), a.end())
#define UNIQUE(x) (x).resize(unique(all(x))-(x).begin())
#define bp(x)  __bulitin_popcount(x)
using namespace std;
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}


const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;

ll a[3001];

int main()
{
boost
ll n,s;
cin>>n>>s;
loop(i,0,n)cin>>a[i];
    ll sum=s;

    ll dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
  //loop(i,0,n+1)dp[i][0]++;
loop(i,1,n+1){
   dp[i-1][0]++;
    loop(j,0,sum+1){
        dp[i][j]=dp[i-1][j];
      
if(j>=a[i-1]){dp[i][j]=(dp[i-1][j-a[i-1]]+dp[i][j])%FMOD;   }
}}
ll ans=0;
/*loop(i,0,n+1){
    loop(j,0,sum+1)cout<<dp[i][j]<<" ";
    cout<<"\n"; 
}*/
loop(i,1,n+1)ans+=dp[i][sum],ans%=FMOD;
cout<<ans<<"\n";

return 0;
}
