/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

const int MAX_V = 5000;

class UnionFind {
public:
    // コンストラクタ
    explicit UnionFind(int N) : V_NUM(N) {
        for (int i = 0; i < V_NUM; ++i) {
            par[i] = i;
        }
        fill(rank, rank + V_NUM, 0);
    }

    // xの親を返す+更新
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // xとyを含むグループを統合する
    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        // rank[x] >= rank[y]にする
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }

    // xとyが同じグループに属するか判定
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int V_NUM;
    int par[MAX_V], rank[MAX_V];
};

tuple<ll, int, int> edges[500000];
vector<pair<int, ll>> path[5000];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = mt(c, --a, --b);
    }

    sort(edges, edges + M);
    UnionFind uf(N);

    // 最小全域木の辺とコスト
    ll total = 0;

    // Kruskalで最小全域木を構築
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        tie(c, a, b) = edges[i];

        if (uf.same(a, b)) continue;
        uf.unite(a, b);
        total += c;
        path[a].push_back(mp(b, c));
        path[b].push_back(mp(a, c));
    }

    // d[v] = 0を親としたときのノードvの深さ
    int d[N];
    fill(d, d + N, -1);
    d[0] = 0;

    // lca[x][v] = (vから2^xだけ遡った頂点,
    //              そこに行くまでに辿った辺でのコストの最大値)
    pair<int, ll> lca[15][N];
    lca[0][0] = mp(0, 0);

    // 幅優先探索でdとlca[0]を埋める
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto p : path[v]) {
            int sv;
            ll cost;
            tie(sv, cost) = p;
            if (d[sv] >= 0) continue;

            d[sv] = d[v] + 1;
            lca[0][sv] = mp(v, cost);
            que.push(sv);
        }
    }

    // lcaを埋める
    for (int x = 1; x < 15; ++x) {
        for (int v = 0; v < N; ++v) {
            int mid = lca[x - 1][v].first;
            ll cost = max(lca[x - 1][v].second, lca[x - 1][mid].second);

            lca[x][v] = mp(lca[x - 1][mid].first, cost);
        }
    }

    // ようやくクエリ処理
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;

        ll trim = 0;
        if (d[s] > d[t]) swap(s, t);
        // d[s] <= d[t]

        // tの深さをsに合わせる
        while (d[s] < d[t]) {
            // sより浅くないtの祖先を漁る
            for (int x = 14; x >= 0; --x) {
                // 祖先が浅すぎる
                if (x > 0 && d[s] > d[lca[x][t].first]) continue;
                trim = max(trim, lca[x][t].second);
                t = lca[x][t].first;
                break;
            }
        }

        // LCAを探す
        while (s != t) {
            for (int x = 14; x >= 0; --x) {
                // 祖先が浅すぎる
                if (x > 0 && lca[x][s].first == lca[x][t].first) continue;
                trim = max(trim, max(lca[x][s].second, lca[x][t].second));
                s = lca[x][s].first;
                t = lca[x][t].first;
                break;
            }
        }

        cout << total - trim << endl;
    }
    return 0;
}
