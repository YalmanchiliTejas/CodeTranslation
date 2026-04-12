#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x) x
#define rep(...) MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define mp make_pair
#define write(x) cout<<(x)<<"\n"
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vll; template<class T>using vv = vector<vector<T>>;
template<class T>vv<T> vvec(size_t n, size_t m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T>bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>bool chmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 28, MOD = int(1e9) + 7; constexpr ll LINF = 1ll << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); }; }aaaa;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    UnionFind() {}
    void init(int size) { parent.assign(size, -1); rank.assign(size, 0); }
    int operator[](int x) { return find(x); }
    int find(int x) { return parent[x] < 0 ? x : (parent[x] = find(parent[x])); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -parent[find(x)]; }
    bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return 0;
        return rank[x] = max(rank[x], rank[y] + 1), parent[x] += parent[y], parent[y] = x, 1;
    }
    bool uniteByRank(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return 0;
        else if (rank[x] < rank[y]) swap(x, y);
        else if (rank[x] == rank[y]) ++rank[x];
        return parent[x] += parent[y], parent[y] = x, 1;
    }
    bool uniteBySize(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return 0;
        else if (size(x) < size(y)) swap(x, y);
        return rank[x] = max(rank[x], rank[y] + 1), parent[x] += parent[y], parent[y] = x, 1;
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> xy(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        xy[i] = mp(mp(x, y), i);
    }

    vector<pair<int, pair<int, int>>> edges;
    sort(all(xy));
    rep(i, N - 1) {
        edges.emplace_back(abs(xy[i].first.first - xy[i + 1].first.first), mp(xy[i].second, xy[i + 1].second));
    }
    sort(all(xy), [](auto& l, auto& r) { return l.first.second < r.first.second; });
    rep(i, N - 1) {
        edges.emplace_back(abs(xy[i].first.second - xy[i + 1].first.second), mp(xy[i].second, xy[i + 1].second));
    }
    sort(all(edges));

    UnionFind uf;
    uf.init(N);
    ll ans = 0;
    rep(i, edges.size()) {
        if (uf.uniteByRank(edges[i].second.first, edges[i].second.second)) {
            ans += edges[i].first;
        }
    }
    write(ans);
}