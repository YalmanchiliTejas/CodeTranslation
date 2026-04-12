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
template<class T, class U>bool chmax(T& a, U&& b) { return a < b ? a = b, 1 : 0; }
template<class T, class U>bool chmin(T& a, U&& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int main() {
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    for (auto&& c : K) c -= '0';

    vv<vector<ll>> dp = vvec(N + 1, 2, vector<ll>(D));
    dp[0][1][0] = 1;
    rep(i, N) rep(j, 10) rep(k, D) {
        dp[i + 1][0][(j + k) % D] = (dp[i + 1][0][(j + k) % D] + dp[i][0][k]) % MOD;
        if (j < K[i]) dp[i + 1][0][(j + k) % D] = (dp[i + 1][0][(j + k) % D] + dp[i][1][k]) % MOD;
        else if (j == K[i]) dp[i + 1][1][(j + k) % D] = (dp[i + 1][1][(j + k) % D] + dp[i][1][k]) % MOD;
    }

    write((dp[N][0][0] + dp[N][1][0] - 1 + MOD) % MOD);
}