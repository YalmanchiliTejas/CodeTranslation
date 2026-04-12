#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 60) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
template <class T>
void readv(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    V<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    V<V<V<ll>>> dp(n + 1, V<V<ll>>(10, V<ll>(2, -INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int u = i / 2 + (i % 2 > 0);
        for (int j = max(0, u - 5); j <= u; j++) {
            if (i % 2) {
                chmax(dp[i][u - j][1], dp[i - 1][u - j][0] + a[i - 1]);
                if (u - j > 0) {
                    chmax(dp[i][u - j][0], dp[i - 1][u - j - 1][1]);
                    chmax(dp[i][u - j][0], dp[i - 1][u - j - 1][0]);
                }
            } else {
                chmax(dp[i][u - j][1], dp[i - 1][u - j + 1][0] + a[i - 1]);
                chmax(dp[i][u - j][0], dp[i - 1][u - j][1]);
                chmax(dp[i][u - j][0], dp[i - 1][u - j][0]);
            }
        }
    }
    cout << max(dp[n][n % 2][0], dp[n][n % 2][1]) << '\n';
}