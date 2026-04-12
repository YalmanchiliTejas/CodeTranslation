#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vi = vector<int>;
using vb = vector<bool>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vpll = vector<pll>;
const ll LINF = 1ll << 55;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

/// cin/cout overloading
template <typename T>
ostream &operator<<(ostream &out, vector<T> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        out << *it << " ";
    }
    return out;
}

template <typename T>
ostream &operator<<(ostream &out, pair<T, T> &P) {
    out << P.first << " " << P.second;
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        in >> *it;
    }
    return in;
}

template <typename T>
istream &operator>>(istream &in, pair<T, T> &P) {
    in >> P.first >> P.second;
    return in;
}

#define coutp(x, y) cout << (x) << " " << (y) << endl
#define coutn(x) cout << (x) << endl
#define coutd(x) cout << setprecision(10) << (x) << endl

/// 图相关
// ll N, M;

// struct Edge {
//     int to;
//     ll weight;
//     int next;
//     bool operator<(const Edge &rhs) { return weight < rhs.weight; }
// };

// template <typename T>
// struct Edge2 {
//     T from, to, weight;
//     Edge2(T from_, T to_, T weight_) : from(from_), to(to_), weight(weight_)
//     {} Edge2() : from(T(0)), to(T(0)), weight(T(0)) {} bool operator<(const
//     Edge2 &rhs) { return weight < rhs.weight; }
// };

// vector<Edge> edges(MAXN << 1);
// vi head(MAXN, -1);
// vector<int> matchingx(MAXN, -1);
// vector<int> matchingy(MAXN, -1);
// vector<bool> check(MAXN);
// vector<ll> dis(MAXN);
// vector<bool> vis(MAXN, false);

// int cnt = 1;

// void addEdge(int from, int to, ll weight) {
//     edges[cnt].to = to;
//     edges[cnt].weight = weight;
//     edges[cnt].next = head[from];
//     head[from] = cnt++;
// }

// bool dfs(int u) {
//     for (int i = head[u]; i != -1; i = edges[i].next) {
//         int v = edges[i].to;
//         if (!check[v]) {
//             check[v] = true;
//             if (matchingy[v] == -1 || dfs(matchingy[v])) {
//                 matchingy[v] = u;
//                 matchingx[u] = v;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int hungarian() {
//     int ans = 0;
//     fill(matchingx.begin(), matchingx.end(), -1);
//     fill(matchingy.begin(), matchingy.end(), -1);
//     for (int u = 1; u <= N; ++u) {
//         //        if (matchingx[u] == -1) {
//         {
//             fill(check.begin(), check.end(), false);
//             if (dfs(u)) {
//                 ++ans;
//             }
//         }
//     }
//     return ans;
// }

// void dijkstra(const ll s) {
//     priority_queue<P, vector<P>, greater<P>> que;
//     fill(dis.begin(), dis.end(), INF);
//     dis[s] = 0;
//     que.push(P(0, s));
//     // multiple sources
//     for (auto &x : shops) {
//         dis[x] = 0;
//         que.push(P(0, x));
//     }
//     while (!que.empty()) {
//         P p = que.top();
//         que.pop();
//         cout << "pop " << p.second << endl;
//         int u = p.second;
//         if (dis[u] < p.first) continue;
//         for (int i = head[u]; i != -1; i = edges[i].next) {
//             int v = edges[i].to;
//             if (dis[v] > dis[u] + edges[i].weight) {
//                 dis[v] = dis[u] + edges[i].weight;
//                 cout << "push " << v << endl;
//                 que.push(P(dis[v], v));
//             }
//         }
//     }
// }

// void zeroOneBFS(const int s) {
//     deque<P> que;
//     fill(dis.begin(), dis.end(), INF);
//     dis[s] = 0;
//     que.push_front(P(0, s));
//     while (!que.empty()) {
//         P p = que.front();
//         que.pop_front();
//         int u = p.second;
//         if (dis[u] < p.first) continue;
//         for (int i = head[u]; i != -1; i = edges[i].next) {
//             int v = edges[i].to;
//             if (dis[v] > dis[u] + edges[i].weight) {
//                 dis[v] = dis[u] + edges[i].weight;
//                 if (edges[i].weight) {
//                     que.push_back(P(dis[v], v));
//                 } else {
//                     que.push_front(P(dis[v], v));
//                 }
//             }
//         }
//     }
// }

/// Union-Find 并查集
class UnionFind {
    vector<ll> par;

   public:
    explicit UnionFind(ll n) : par(n, -1) {}

    ll root(ll a) {
        if (par[a] < 0) {
            return a;
        }
        return par[a] = root(par[a]);
    }

    ll size(ll a) { return -par[root(a)]; }

    void unite(ll a, ll b) {
        a = root(a);
        b = root(b);
        if (a != b) {
            if (size(a) < size(b)) {
                swap(a, b);
            }
            par[a] += par[b];
            par[b] = a;
        }
    }
};

// template <typename T>
// ll kruskal(vector<Edge2> &edges2, const ll V) {
//     sort(edges2.begin(), edges2.end());
//     UnionFind uf(V + 10);
//     ll res = 0;
//     Edge2 e;
//     for (int i = 0; i < edges2.size(); ++i) {
//         e = edges2[i];
//         if (uf.root(e.u) != uf.root(e.v)) {
//             uf.unite(e.u, e.v);
//             res += e.w;
//         }
//     }
//     return res;
// }

/// 线段树
// struct SegmentTreeNode {
//     ll maxVal;
//     ll minVal;
//     ll sum;
//     ll len;
//     ll lazy;
//     ll left, right;
//     SegmentTreeNode() {}
// };

// class SegmentTree {
//    public:
//     explicit SegmentTree(size_t size, const vll &nums)
//         : tree(size << 2), nums(nums) {}
//     void build(ll root, ll left, ll right) {
//         tree[root].lazy = 0;
//         tree[root].left = left;
//         tree[root].right = right;
//         tree[root].len = right - left + 1;
//         if (left == right) {
//             tree[root].maxVal = nums[left];
//             tree[root].minVal = nums[left];
//             tree[root].sum = nums[left];
//         } else {
//             ll mid = (right - left) / 2 + left;
//             build(root * 2, left, mid);
//             build(root * 2 + 1, mid + 1, right);
//             tree[root].minVal =
//                 min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//             tree[root].maxVal =
//                 max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//             tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//         }
//     }

//     void pushup(ll root) {
//         tree[root].minVal =
//             min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//         tree[root].maxVal =
//             max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//         tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//     }
//     // add single node val
//     void add(ll root, ll id, ll addVal) {
//         if (tree[root].left == tree[root].right) {
//             tree[root].maxVal += addVal;
//             tree[root].minVal += addVal;
//             tree[root].sum += addVal;
//             return;
//         }
//         ll mid = (tree[root].right - tree[root].left) / 2 + tree[root].left;
//         if (id <= mid) {
//             add(root * 2, id, addVal);
//         } else {
//             add(root * 2 + 1, id, addVal);
//         }
//         pushup(root);
//     }

//     void pushdown(ll root) {
//         if (tree[root].lazy) {
//             tree[root * 2].lazy += tree[root].lazy;
//             tree[root * 2 + 1].lazy += tree[root].lazy;
//             tree[root * 2].sum += tree[root * 2].len * tree[root].lazy;
//             tree[root * 2 + 1].sum += tree[root * 2 + 1].len * tree[root].lazy;
//             tree[root * 2].maxVal += tree[root].lazy;
//             tree[root * 2 + 1].maxVal += tree[root].lazy;
//             tree[root * 2].minVal += tree[root].lazy;
//             tree[root * 2 + 1].minVal += tree[root].lazy;
//             tree[root].lazy = 0;
//         }
//     }
//     // query range sum
//     ll querySum(ll root, ll left, ll right) {
//         if (tree[root].left >= left && tree[root].right <= right) {
//             return tree[root].sum;
//         }
//         if (tree[root].left > right || tree[root].right < left) {
//             return 0;
//         }
//         if (tree[root].lazy) {
//             pushdown(root);
//         }
//         return querySum(root * 2, left, right) +
//                querySum(root * 2 + 1, left, right);
//     }
//     // query range max/min
//     ll queryMax(ll root, ll left, ll right) {
//         if (tree[root].left >= left && tree[root].right <= right) {
//             return tree[root].maxVal;
//         }
//         if (tree[root].left > right || tree[root].right < left) {
//             return -INF;
//         }
//         if (tree[root].lazy) {
//             pushdown(root);
//         }
//         return max(queryMax(root * 2, left, right),
//                    queryMax(root * 2 + 1, left, right));
//     }

//     ll queryMin(ll root, ll left, ll right) {
//         if (tree[root].left >= left && tree[root].right <= right) {
//             return tree[root].minVal;
//         }
//         if (tree[root].left > right || tree[root].right < left) {
//             return INF;
//         }
//         if (tree[root].lazy) {
//             pushdown(root);
//         }
//         return min(queryMin(root * 2, left, right),
//                    queryMin(root * 2 + 1, left, right));
//     }
//     // add range val
//     void update(ll root, ll left, ll right, ll addVal) {
//         if (tree[root].left >= left && tree[root].right <= right) {
//             tree[root].lazy += addVal;
//             tree[root].sum += tree[root].len * addVal;
//             tree[root].maxVal += addVal;
//             tree[root].minVal += addVal;
//             return;
//         }
//         if (tree[root].left > right || tree[root].right < left) {
//             return;
//         }
//         if (tree[root].lazy) {
//             pushdown(root);
//         }
//         update(root * 2, left, right, addVal);
//         update(root * 2 + 1, left, right, addVal);
//         pushup(root);
//     }

//    private:
//     vector<SegmentTreeNode> tree;
//     const vll &nums;
// };

/// 组合数

/// 約数求める
// void divisor(ll n, vector<ll> &ret) {
//     for (ll i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             ret.push_back(i);
//             if (i * i != n) ret.push_back(n / i);
//         }
//     }
//     sort(ret.begin(), ret.end());
// }
/// 階乗
ll factorial(ll n) {
    ll ret = 1;
    for (ll i = 1; i <= n; ++i) {
        ret = (ret * i) % MOD;
    }
    return ret;
}
/// モジュラ逆数
ll inv_mod(ll n) {
    ll a = n % MOD, b = MOD - 2, ret = 1;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll nPr(ll n, ll r) {
    ll ret = 1;
    for (ll i = n; i >= n - r + 1; --i) {
        ret = ret * (i % MOD) % MOD;
    }
    return ret;
}

ll nCr(ll n, ll r) {
    if (r > n - r) {
        return nCr(n, n - r);
    }
    return nPr(n, r) * inv_mod(factorial(r)) % MOD;
}
// Choosing r items from n types of items possibly with duplicates of types.
// Or putting r balls in n boxes possibly with empty boxes. (balls are same but boxes aren't)
ll nHr(ll n, ll r) {
    return nCr(n + r - 1, n - 1);
}

// vll F(MAXN), Finv(MAXN), inv(MAXN);

// void comb_init() {
//     inv[1] = 1;
//     for (int i = 2; i < MAXN; ++i) {
//         inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
//     }
//     F[0] = Finv[0] = 1;
//     for (int i = 1; i < MAXN; ++i) {
//         F[i] = F[i - 1] * 1ll * i % MOD;
//         Finv[i] = Finv[i - 1] * 1ll * inv[i] % MOD;
//     }
// }

// inline ll comb(ll n, ll m) {
//     if (m < 0 || m > n) return 0;
//     return F[n] * inv[n - m] % MOD * inv[m] % MOD;
// }

// inline ll comb_h(ll n, ll m) {
//     return comb(n + m - 1, n - 1);
// }

inline ll ADD(ll a, ll b) { return (a + b) % MOD; }

inline ll MUL(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

inline ll SUB(ll a, ll b) { return (a + MOD - b) % MOD; }

inline ll POW(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

/// main函数
int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    vector<vll> dp1(N, vll(5));
    vector<vll> dp0(N, vll(5));
    dp0[0][0] = 1;
    dp0[0][1] = (S[0] - '0') - 1;
    dp1[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        dp0[i][0] = 1;
        for (int j = 1; j <= K; ++j) {
            dp0[i][j] += dp0[i - 1][j - 1] * 9;
            dp0[i][j] += dp0[i - 1][j];
            if (S[i] != '0') {
                dp0[i][j] += dp1[i - 1][j - 1] * (S[i] - '0' - 1);
                dp0[i][j] += dp1[i - 1][j];
                dp1[i][j] += dp1[i - 1][j - 1];
            } else {
                dp1[i][j] += dp1[i - 1][j];
            }
        }
    }
    coutn(dp0[N - 1][K] + dp1[N - 1][K]);
	return 0; 
} 