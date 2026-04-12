#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
using namespace std;
using ll = long long;
template<typename T>
inline bool chmax(T& a, const T& b) {
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T> vector<T> make_vec(size_t n) { return vector<T>(n); }
template<typename T, typename... Args> auto make_vec(size_t n, Args... args) {
    return vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(args...));
}
template<typename T, typename U, typename... V>
typename enable_if<is_same<T, U>::value>::type fill_v(U& u, const V... v) { u = U(v...); }
template<typename T, typename U, typename... V>
typename enable_if<!is_same<T, U>::value>::type fill_v(U& u, const V... v) {
    for (auto& e : u) fill_v<T>(e, v...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    auto dp = make_vec<ll>(n+1, k+1, 2);
    dp[0][0][0] = 1;
    rep(i, n) {
        int x = s[i] - '0';
        rep(j, k+1) {
            rep(flag, 2) {
                for (int y = 0; y <= (flag ? 9 : x); ++y) {
                    int ni = i+1;
                    int nj = j + (y != 0);
                    int nflag = (flag || y < x);
                    if (nj <= k) dp[ni][nj][nflag] += dp[i][j][flag];
                }
            }
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << '\n';
}
