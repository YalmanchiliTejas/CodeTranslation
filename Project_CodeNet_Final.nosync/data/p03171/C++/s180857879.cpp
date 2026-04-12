
#pragma region

#ifdef LOCAL
#define debug cout
#else
#define debug \
    if (0) cout
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";
    for (auto e : v) os << e << " ";
    return os << "]";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
    return os << "( " << x.first << ", " << x.second << " )";
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
    return is >> x.first >> x.second;
}

void solve();

int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
}

#pragma endregion

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));
    for (int s = 1; s <= n; ++s) {
        for (int i = 1; i + s - 1 <= n; ++i) {
            int j = i + s - 1;
            if (s % 2 == n % 2) {
                dp[i][j] = max(a[i - 1] + dp[i + 1][j], a[j - 1] + dp[i][j - 1]);
            } else {
                dp[i][j] = min(-a[i - 1] + dp[i + 1][j], -a[j - 1] + dp[i][j - 1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}