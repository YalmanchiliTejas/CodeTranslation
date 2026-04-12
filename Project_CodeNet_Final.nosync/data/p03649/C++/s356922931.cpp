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

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; ++i) cin >> a.at(i);

    auto check = [n, &a]() -> int {
        ll maxi = -1;
        int ind = -1;
        for (int i=0; i<n; ++i) if (chmax(maxi, a.at(i))) ind = i;
        return ind;
    };

    ll res = 0;
    while (true) {
        int ind = check();
        if (a.at(ind) < n) break;
        ll tmp = a.at(ind) / n;
        res += tmp;
        for (int i=0; i<n; ++i) {
            if (i == ind) a.at(i) = a.at(i) % n;
            else a.at(i) += tmp;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
