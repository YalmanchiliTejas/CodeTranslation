#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((ll)(x).size())

const double PI  = acos(-1.0);
const double EPS = 1e-9;
const ll INF = 1e9+10;
const ll MOD = 998244353;
//const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(x) cerr << #x << " is " << x << endl;

//ll dp[3001][3001];
ll dp[3001];

int main() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N + 1);
    rep(i, N)cin >> A[i + 1];
    
    ll ans = 0;
    reps(i, 1, N + 1){
        dp[S] = 0;
        for (int j = S; j > A[i]; j--){
            (dp[j] += dp[j - A[i]])%=MOD;
        }
        (dp[A[i]] += i) %= MOD;
        (ans += dp[S] * (N - i + 1))%=MOD;
#if 0        
        (dp[i][A[i]] += i) %= MOD;
        rep(j, S + 1){
            if (j != S)
                (dp[i][j] += dp[i - 1][j])%=MOD;
            if (j > A[i])
                (dp[i][j] += dp[i - 1][j - A[i]])%=MOD;
        }
        (ans += dp[i][S] * (N - i + 1))%=MOD;
        //rep(j, S + 1){
        //    fprintf(stderr, "dp[%d][%d] = %d\n", i, j, dp[i][j]);
        //}
#endif
    }
    cout << ans;
    return 0;
}

