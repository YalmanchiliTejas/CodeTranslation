#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define dump(x)
#define debug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, std::vector<long long> A){
    // dp[used num is larger than 2/n][until i]
    vector<vector<ll>> dp(3, vector<ll> (N+1));
    rep(i,0,N) {
        if (i % 2 == 0) {
            dp[2][i+1] = (i>0 ? dp[2][i-1] : 0) + A[i];
            dp[1][i+1] = max((i>0 ? dp[1][i-1] : 0) + A[i], dp[1][i]);
        } else {
            dp[1][i+1] = max((i>0 ? dp[1][i-1] : 0) + A[i], dp[2][i]);
            dp[0][i+1] = max((i>0 ? dp[0][i-1] : 0) + A[i], dp[1][i]);
        }
    }
    cout << dp[1][N] << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
