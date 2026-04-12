#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
constexpr int INF = 1 << 29, MOD = 998244353; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vv<int> dp = vvec(N + 1, 6001, 0);
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, 1, S + 1) dp[i + 1][j] = dp[i][j];
        if (A[i] > S) continue;
        else if (A[i] == S) {
            dp[i + 1][S] = (dp[i + 1][S] + (ll)(i + 1) * (N - i)) % MOD;
        }
        else {
            dp[i + 1][A[i]] = (dp[i + 1][A[i]] + i + 1) % MOD;
            rep(j, 1, S - A[i]) {
                dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % MOD;
            }
            dp[i + 1][S] = (dp[i + 1][S] + (ll)dp[i][S - A[i]] * (N - i)) % MOD;
        }
    }
    write(dp[N][S]);
}