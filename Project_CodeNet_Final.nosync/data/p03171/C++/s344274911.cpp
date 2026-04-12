#include <bits/stdc++.h>
using namespace std;

template <typename T> T load() { T r; cin >> r; return r; }
template <typename T> vector<T> loadMany(int n) { vector<T> rs(n); generate(rs.begin(), rs.end(), &load<T>); return rs; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto n = load<int>();
    auto reward = loadMany<int>(n);
    auto dyn = array<vector<vector<long long>>, 2>{
        vector<vector<long long>>(n+1, vector<long long>(n+1)),
        vector<vector<long long>>(n+1, vector<long long>(n+1))
    };
    for (auto i=0; i<n; ++i)
        dyn[0][i][i] = 0ll, dyn[1][i][i] = 0ll;
    for (auto l=1; l<=n; ++l) {
        for (auto i=0; i+l<=n; ++i) {
            dyn[0][i][i+l] = max(
                reward[i] + dyn[1][i+1][i+l],
                reward[i+l-1] + dyn[1][i][i+l-1]
            );
            dyn[1][i][i+l] = min(
                dyn[0][i+1][i+l] - reward[i],
                dyn[0][i][i+l-1] - reward[i+l-1]
            );
        }
    }
    cout << dyn[0][0][n] << '\n';
}
