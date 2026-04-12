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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> G(n, vector<bool>(n, false));
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).at(b-1) = true;
        G.at(b-1).at(a-1) = true;
    }
    vector<int> v(n-1);
    for (int i=0; i<n-1; ++i) v.at(i) = i+1;
    int res = 0;
    do {
        bool ok = true;
        if (!G.at(0).at(v.at(0))) ok = false;
        for (int i=0; i<n-2; ++i) {
            if (!G.at(v.at(i)).at(v.at(i+1))) {
                ok = false;
                break;
            }
        }
        if (ok) ++res;
    } while (next_permutation(v.begin(), v.end()));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
