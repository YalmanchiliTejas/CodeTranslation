#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define INPUTL(i,n) for(ll i=0 ; i<n ; i++)
const int MOD = 1000000007 ; // 1000000009 , 1000000023 ,998244353
const ll INF = (1e18);
const ll infinity = (1e9);
const ld PI = 4*atan((ld)1);


ll power(ll x,ll n,ll MOD)
{
    ll result=1;
    while(n>0){
        if(n&1)result = (result * x)%MOD;
        x=(x*x)%MOD;
        n >>= 1;
    }
    return result%MOD;
}

ll gcd(ll a , ll b){
  if(a==0)return b;
  return gcd(b%a,a);
}
ll n;
vector<ll>ar;
vector<vector<ll>>dp(3*1001,vector<ll>(3*1001));

ll solve(ll i,ll j,ll t){
  if(dp[i][j]!=-1)return dp[i][j];
  if(i==j)return 0;
  if(t)return dp[i][j] = min(solve(i+1,j,0) - ar[i] , solve(i,j-1,0) - ar[j-1]);
  else return dp[i][j] = max(solve(i+1,j,1) + ar[i] , solve(i,j-1,1) + ar[j-1]);
}
int main() {
    #ifdef AVI  
        freopen("input.txt" , "r" , stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    
    cin >> n;
    ar = vector<ll>(n);
    for(auto &x:ar)cin >> x;
    dp = vector<vector<ll>>(n+1,vector<ll>(n+1,-1));
    cout << solve(0,n,0);
}