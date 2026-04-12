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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vv<ll> dp = vvec(N + 1, N + 1, 0LL);
    rep(i, N + 1) rep(j, N + 1) dp[i][j] = i % 2 ? LINF : -LINF;
    rep(j, N + 1) dp[N][j] = 0;

    for (int i = N - 1; i >= 0; --i) rep(j, i + 1) {
        if (i % 2) {
            dp[i][j] = min(dp[i + 1][j] - a[i - j], dp[i + 1][j + 1] - a[N - 1 - j]);
        }
        else {
            dp[i][j] = max(dp[i + 1][j] + a[i - j], dp[i + 1][j + 1] + a[N - 1 - j]);
        }
    }

    write(dp[0][0]);
}