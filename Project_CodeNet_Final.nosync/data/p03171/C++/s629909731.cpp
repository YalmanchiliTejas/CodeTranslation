#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

ll rec(int i, int j, vector<vector<ll>> &dp, const vector<ll> &a) {
    if (dp.at(i).at(j) != LINF) return dp.at(i).at(j);

    if (i == j) return dp.at(i).at(j) = a.at(i);
    else return dp.at(i).at(j) = max(a.at(i) - rec(i+1, j, dp, a), a.at(j) - rec(i, j-1, dp, a));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }

    vector<vector<ll>> dp(n, vector<ll>(n, LINF));

    cout << rec(0, n-1, dp, a) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
