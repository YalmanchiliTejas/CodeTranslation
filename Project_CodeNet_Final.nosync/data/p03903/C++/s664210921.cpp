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

int main() {
    int N, M;
    cin >> N >> M;

    tuple<ll, int, int> edges[M];
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = mt(c, --a, --b);
    }

    sort(edges, edges + M);
    UnionFind uf(N);

    // 最小全域木の辺とコスト
    vector<pair<int, ll>> path[N];
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

    ll emax[N][N];
    // emax[i][j] = iからjのパス上で最大コストの辺のコスト

    for (int r = 0; r < N; ++r) {
        fill(emax[r], emax[r] + N, -1);
        emax[r][r] = 0;
        queue<int> que;
        que.push(r);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto p : path[v]) {
                int sv;
                ll cost;
                tie(sv, cost) = p;

                if (emax[r][sv] >= 0) continue;
                emax[r][sv] = max(emax[r][v], cost);
                que.push(sv);
            }
        }
    }

    // クエリ処理
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int s, t;
        cin >> s >> t;
        cout << total - emax[--s][--t] << endl;
    }
    return 0;
}
