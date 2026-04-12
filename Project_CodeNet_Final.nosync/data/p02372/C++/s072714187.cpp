#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
using namespace std;
using ll = long long;
template<typename T>
inline bool chmax(T& a, const T& b) {
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
template<typename T>
inline bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T> vector<T> make_vec(size_t n) { return vector<T>(n); }
template<typename T, typename... Args> auto make_vec(size_t n, Args... args) {
    return vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(args...));
}
template<typename T, typename U, typename... V>
typename enable_if<is_same<T, U>::value>::type fill_v(U& u, const V... v) { u = U(v...); }
template<typename T, typename U, typename... V>
typename enable_if<!is_same<T, U>::value>::type fill_v(U& u, const V... v) {
    for (auto& e : u) fill_v<T>(e, v...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    auto g = make_vec<pair<int, int>>(n, 0);
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<int> dist1(n), dist2(n);
    auto dfs = [&](auto self, vector<int>& dist, int v, int p = -1) -> void {
        for (auto uw : g[v]) {
            int u = uw.first, w = uw.second;
            if (u == p) continue;
            dist[u] = dist[v] + w;
            self(self, dist, u, v);
        }
    };

    dfs(dfs, dist1, 0);
    int v = distance(dist1.begin(), max_element(dist1.begin(), dist1.end()));
    dist1.assign(n, 0);
    dfs(dfs, dist1, v);
    int u = distance(dist1.begin(), max_element(dist1.begin(), dist1.end()));
    dfs(dfs, dist2, u);

    rep(i, n) cout << max(dist1[i], dist2[i]) << '\n';
}

