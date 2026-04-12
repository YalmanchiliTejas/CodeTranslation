#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    string K;
    cin >> K;
    int D;
    cin >> D;
    int mod = 1e9 + 7;
    int N = K.size();
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(D, vector<int>(2)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            for (int k = 0; k <= K[i] - '0'; k++) {
                dp[i + 1][(j + k) % D][(k != (K[i] - '0'))] += dp[i][j][0];
                dp[i + 1][(j + k) % D][(k != (K[i] - '0'))] %= mod;
            }
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % D][1] += dp[i][j][1];
                dp[i + 1][(j + k) % D][1] %= mod;
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][0][1] + mod - 1) % mod << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}