#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

int dp[10001][2][101];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string K;
    ll D;
    cin >> K >> D;
    dp[0][1][0] = 1;
    rep(i, K.size()) {
        int x = K[i] - '0';
        rep(j, 2) {
            for (int d = 0; d <= (j == 1 ? x : 9); d++) {
                rep(d2, D) {
                    dp[i + 1][(j == 1 and d == x)][(d + d2) % D] += dp[i][j][d2];
                    dp[i + 1][(j == 1 and d == x)][(d + d2) % D] %= mod;
                }
            }
        }
    }
    // rep(i, K.size() + 1) rep(j, 2) rep(k, D) {
    //     cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    // }
    cout << (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + mod) % mod << endl;
    return 0;
}
