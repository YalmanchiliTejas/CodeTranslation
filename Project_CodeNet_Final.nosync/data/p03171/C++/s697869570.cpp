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


ll dp[3001][3001];
vector<ll> A;

ll dfs(int i, int j, int turn) {
    if (i > j) {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (turn == 0) {
        return dp[i][j] = max(A[i] + dfs(i + 1, j, 1 - turn), A[j] + dfs(i, j - 1, 1 - turn));
    } else {
        return dp[i][j] = min(dfs(i + 1, j, 1 - turn), dfs(i, j - 1, 1 - turn));
    }
}

void solve() {
    int N;
    cin >> N;
    A.resize(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 3001; j++) {
            dp[i][j] = -1;
        }
    }
    ll X = dfs(0, N - 1, 0);
    ll Y = sum - X;
    cout << X - Y << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}