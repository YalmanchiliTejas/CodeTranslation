#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
//const ll MOD = 1e9+7;
const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, S;
    cin >> N >> S;
    int A[N];
    rep(i, N) cin >> A[i];
    //dp[i][j]:=A[0]からA[i-1]までで総和をjになるようにとるとり方(重み付き)
    ll dp[N+1][S+1];
    ll ans = 0;
    fill(dp[0], dp[N+1], 0);
    rep(i, N){
        rep(j, S+1) dp[i+1][j] = dp[i][j];
        rep3(j, S, A[i]+1){
            dp[i+1][j] += dp[i][j-A[i]];
            dp[i+1][j] %= MOD;
        }
        if(A[i] <= S){
            dp[i+1][A[i]] += i+1;
          	dp[i+1][A[i]] %= MOD;
        }
        ans += (N-i)*(MOD+dp[i+1][S]-dp[i][S]);
        ans %= MOD;
    }
    cout << ans << endl;
}