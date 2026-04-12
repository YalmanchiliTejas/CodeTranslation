#include<bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(ll i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define pb push_back
#define X first
#define Y second

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
const ll INF = 1e18+1;
const ll MOD = 998244353L;

#ifdef umang99m
    #include "/home/umang/.templates/header.h"
#else
    #define dbg(args...)
    #define timer()
#endif

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n,s;
    cin>>n>>s;
    vi a(n+1);
    repA(i,1,n) cin>>a[i];

    ll dp[n+1][s+1];
    ll dp1[n+1][s+1];
    memset(dp, 0, sizeof dp);
    memset(dp1, 0, sizeof dp);
    /*
     * dp[i][j] = dp[i-1][j] for all j;
     * dp[i][A[i]] += i;
     * for j > A[i], dp[i][j] += dp[i-1][j-A[i]];
    */

    repA(i,1,n){
        repA(j,1,s){
            if(j > a[i])
                dp[i][j] = dp1[i-1][j-a[i]];
            else if(j == a[i]){
                dp[i][j] = i;
            }
            dp[i][j] %= MOD;
            dp1[i][j] = dp1[i-1][j] + dp[i][j];
            dp1[i][j] %= MOD;
        }
    }


    ll ans = 0;
    repA(i,1,n){
        ans+=((n-i+1)*dp[i][s])%MOD;
        ans %= MOD;
    }

    cout<<ans<<endl;

    timer();
    return 0;
}
