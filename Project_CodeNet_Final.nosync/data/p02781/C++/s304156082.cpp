#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

template <class T> using max_heap = priority_queue<T>;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U> void chmax(T &a, U b) {
    if (a < b)
        a = b;
}
template <class T, class U> void chmin(T &a, U b) {
    if (b < a)
        a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

int dp[101][2][4];

void solve(string N, long long K) {
    dp[0][0][0] = 1;
    rep(i, N.size()) {
        const int D = N[i] - '0';
        rep(j, 2) {
            rep(k, K) {
                rep(d, (j ? 10 : D + 1)) {
                    // int _k = k;
                    if (d != 0)
                        dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
                    else
                        dp[i + 1][j || (d < D)][k] += dp[i][j][k];

                    // cout << "(" << i << "," << j << "," << k << ")";
                    // cout << " -> ";
                    // cout << "(" << i + 1 << "," << (j || (d < D)) << ","
                    //      << k + 1 << ")";

                    // cout << i + 1 << " " << (j || (d < D)) << " " << k + 1
                    //      << " " << d << " " << dp[i + 1][j || (d < D)][k + 1]
                    //      << endl;
                    // cout << i << " " << j << " " << k << " " << d << " "
                    //      << dp[i + 1][j || (d < D)][_k] << endl;

                    // debug(dp[i + 1][j || (d < D)][_k])
                }
            }
        }
    }
    int sum = 0;
    rep(i, N.size() + 1) rep(j, 2) { sum += dp[i][j][K]; }
    cout << sum << endl;
    // cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string N;
    cin >> N;
    long long K;
    cin >> K;
    solve(N, K);
    return 0;
}
