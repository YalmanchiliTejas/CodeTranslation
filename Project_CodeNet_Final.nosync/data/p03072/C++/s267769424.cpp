#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MAXN = 200000 + 50;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

/// 图相关
ll N, M;

struct Edge {
    ll to;
    ll weight;
    ll next;
};

vector<Edge> edges(MAXN);
vector<ll> head(MAXN, -1);
vector<int> matchingx(MAXN, -1);
vector<int> matchingy(MAXN, -1);
vector<bool> check(MAXN);
vector<ll> dis(MAXN);
vector<bool> vis(MAXN, false);

ll cnt = 1;

void addEdge(ll from, ll to, ll weight) {
    edges[cnt].to = to;
    edges[cnt].weight = weight;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}
//
//bool dfs(int u) {
//    for (int i = head[u]; i != -1; i = edges[i].next) {
//        int v = edges[i].to;
//        if (!check[v]) {
//            check[v] = true;
//            if (matchingy[v] == -1 || dfs(matchingy[v])) {
//                matchingy[v] = u;
//                matchingx[u] = v;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int hungarian() {
//    int ans = 0;
//    fill(matchingx.begin(), matchingx.end(), -1);
//    fill(matchingy.begin(), matchingy.end(), -1);
//    for (int u = 1; u <= N; ++u) {
////        if (matchingx[u] == -1) {
//        {
//            fill(check.begin(), check.end(), false);
//            if (dfs(u)) {
//                ++ans;
//            }
//        }
//    }
//    return ans;
//}
//
//void dijkstra(const ll s) {
//    priority_queue<P, vector<P>, greater<P>> que;
//    fill(dis.begin(), dis.end(), INF);
//    dis[s] = 0;
//    que.push(P(0, s));
//////multiple sources
////    for (auto& x : shops) {
////        dis[x] = 0;
////        que.push(P(0, x));
////    }
//    while (!que.empty()) {
//        P p = que.top();
//        que.pop();
////        cout << "pop " << p.second << endl;
//        int u = p.second;
//        if (dis[u] < p.first) continue;
//        for (int i = head[u]; i != -1; i = edges[i].next) {
//            int v = edges[i].to;
//            if (dis[v] > dis[u] + edges[i].weight) {
//                dis[v] = dis[u] + edges[i].weight;
////                cout << "push " << v << endl;
//                que.push(P(dis[v], v));
//            }
//        }
//    }
//}

//void zeroOneBFS(const int s) {
//    deque<P> que;
//    fill(dis.begin(), dis.end(), INF);
//    dis[s] = 0;
//    que.push_front(P(0, s));
//    while (!que.empty()) {
//        P p = que.front();
//        que.pop_front();
//        int u = p.second;
//        if (dis[u] < p.first) continue;
//        for (int i = head[u]; i != -1; i = edges[i].next) {
//            int v = edges[i].to;
//            if (dis[v] > dis[u] + edges[i].weight) {
//                dis[v] = dis[u] + edges[i].weight;
//                if (edges[i].weight) {
//                    que.push_back(P(dis[v], v));
//                } else {
//                    que.push_front(P(dis[v], v));
//                }
//            }
//        }
//    }
//}
//
//struct TreeNode {
//    int val;
//    TreeNode* left = nullptr;
//    TreeNode* right = nullptr;
//    TreeNode(int val_) : val(val_) {}
//};
//
////int dfs(int cur, int a, int b, int c, const vector<int> &nums) {
////    if (cur >= N) {
////        return (min({a, b, c}) > 0 ? (abs(a - A) + abs(b - B) + abs(c - C) - 30) : INF);
////    }
////    int ret0 = dfs(cur + 1, a, b, c, nums);
////    int ret1 = dfs(cur + 1, a + nums[cur], b, c, nums) + 10;
////    int ret2 = dfs(cur + 1, a, b + nums[cur], c, nums) + 10;
////    int ret3 = dfs(cur + 1, a, b, c + nums[cur], nums) + 10;
////    return min({ret0, ret1, ret2, ret3});
////}
//


//struct HuffmanNode : std::enable_shared_from_this<HuffmanNode> {
//    typedef std::shared_ptr<HuffmanNode> HuffmanNodePtr;
//    int weight;
//    HuffmanNodePtr leftChild;
//    HuffmanNodePtr rightChild;
//    HuffmanNodePtr parent;
//    explicit HuffmanNode(int weight_) : weight(weight_), leftChild(nullptr), rightChild(nullptr) {}
//    bool operator<(const HuffmanNode &rhs) const {
//        return weight > rhs.weight;
//    }
//};
//
////struct cmp {
////    bool operator () (const HuffmanNodePtr x, const HuffNode* y) {
////        return x->weight > y->weight;
////    }
////};
//
//class KthLargest {
//public:
//    KthLargest(int k, vector<int> nums) {
//        this->k = k;
//        for (auto &x : nums) {
//            add(x);
//        }
//    }
//
//    int add(int val) {
//        maxHeap.push(-val);
//        if (maxHeap.size() > k) {
//            maxHeap.pop();
//        }
//        return -maxHeap.top();
//    }
//private:
//    priority_queue<int> maxHeap;
//    int k;
//};
//
//
//int bfs() {
//    queue<P> que;
//    for (int i = 0; i < MAXN; ++i) {
//        for (int j = 0; j < MAXN; ++j) {
//            dis[i][j] = INF;
//        }
//    }
//    dis[sx][sy] = 0;
//    que.push(P(sx, sy));
//    while (!que.empty()) {
//        auto p = que.top();
//        que.pop();
//        if (p.first == gx && p.second == gy) break;
//        for (int i = 0; i < 4; ++i) {
//            int nx = p.first + dx[i];
//            int ny = p.second + dy[i];
//            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && dis[nx][ny] == INF) {
//                que.push(P(nx, ny));
//                dis[nx][ny] = dis[p.first][p.second] + 1;
//            }
//        }
//    }
//    return dis[gx][gy];
//}
//
/// Union-Find 并查集
//class UnionFind {
//    vector<int> par;
//public:
//    explicit UnionFind(int n) : par(n, -1) {}
//
//    int root(int a) {
//        if (par[a] < 0) {
//            return a;
//        }
//        return par[a] = root(par[a]);
//    }
//
//    int size(int a) {
//        return -par[root(a)];
//    }
//
//    void unite(int a, int b) {
//        a = root(a);
//        b = root(b);
//        if (a != b) {
//            if (size(a) < size(b)) {
//                swap(a, b);
//            }
//            par[a] += par[b];
//            par[b] = a;
//        }
//    }
//};
/// 线段树
//struct SegmentTreeNode {
//    ll maxVal;
//    ll minVal;
//    ll sum;
//    ll len;
//    ll lazy;
//    ll left, right;
//    SegmentTreeNode() {}
//};
//
//class SegmentTree {
//public:
//    explicit SegmentTree(size_t size, const vll& nums) : tree(size << 2), nums(nums) {
//
//    }
//    void build(ll root, ll left, ll right) {
//        tree[root].lazy = 0;
//        tree[root].left = left;
//        tree[root].right = right;
//        tree[root].len = right - left + 1;
//        if (left == right) {
//            tree[root].maxVal = nums[left];
//            tree[root].minVal = nums[left];
//            tree[root].sum = nums[left];
//        } else {
//            ll mid = (right - left) / 2 + left;
//            build(root * 2, left, mid);
//            build(root * 2 + 1, mid + 1, right);
//            tree[root].minVal = min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//            tree[root].maxVal = max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//            tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//        }
//    }
//
//    void pushup(ll root) {
//        tree[root].minVal = min(tree[root * 2].minVal, tree[root * 2 + 1].minVal);
//        tree[root].maxVal = max(tree[root * 2].maxVal, tree[root * 2 + 1].maxVal);
//        tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
//    }
////// add single node val
//    void add(ll root, ll id, ll addVal) {
//        if (tree[root].left == tree[root].right) {
//            tree[root].maxVal += addVal;
//            tree[root].minVal += addVal;
//            tree[root].sum += addVal;
//            return;
//        }
//        ll mid = (tree[root].right - tree[root].left) / 2 + tree[root].left;
//        if (id <= mid) {
//            add(root * 2, id, addVal);
//        } else {
//            add(root * 2 + 1, id, addVal);
//        }
//        pushup(root);
//    }
//
//    void pushdown(ll root) {
//        if (tree[root].lazy) {
//            tree[root * 2].lazy += tree[root].lazy;
//            tree[root * 2 + 1].lazy += tree[root].lazy;
//            tree[root * 2].sum += tree[root * 2].len * tree[root].lazy;
//            tree[root * 2 + 1].sum += tree[root * 2 + 1].len * tree[root].lazy;
//            tree[root * 2].maxVal += tree[root].lazy;
//            tree[root * 2 + 1].maxVal += tree[root].lazy;
//            tree[root * 2].minVal += tree[root].lazy;
//            tree[root * 2 + 1].minVal += tree[root].lazy;
//            tree[root].lazy = 0;
//        }
//    }
//    //// query range sum
//    ll querySum(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].sum;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return 0;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return querySum(root * 2, left, right) + querySum(root * 2 + 1, left, right);
//    }
//    //// query range max/min
//    ll queryMax(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].maxVal;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return -INF;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return max(queryMax(root * 2, left, right), queryMax(root * 2 + 1, left, right));
//    }
//
//    ll queryMin(ll root, ll left, ll right) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            return tree[root].minVal;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return INF;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        return min(queryMin(root * 2, left, right), queryMin(root * 2 + 1, left, right));
//    }
//    //// add range val
//    void update(ll root, ll left, ll right, ll addVal) {
//        if (tree[root].left >= left && tree[root].right <= right) {
//            tree[root].lazy += addVal;
//            tree[root].sum += tree[root].len * addVal;
//            tree[root].maxVal += addVal;
//            tree[root].minVal += addVal;
//            return;
//        }
//        if (tree[root].left > right || tree[root].right < left) {
//            return;
//        }
//        if (tree[root].lazy) {
//            pushdown(root);
//        }
//        update(root * 2, left, right, addVal);
//        update(root * 2 + 1, left, right, addVal);
//        pushup(root);
//    }
//
//
//private:
//    vector<SegmentTreeNode> tree;
//    const vll &nums;
//};

/// 组合数
ll F[MAXN], Finv[MAXN], inv[MAXN];

ll pow_mod(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}

void comb_init() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}

inline int comb(ll n, ll m) {
    if (m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}

inline ll add_mod(ll a, ll b) {
    return (a + b) % MOD;
}

inline ll mul_mod(ll a, ll b) {
    return a * b % MOD;
}

inline ll sub_mod(ll a, ll b) {
    return (a + MOD - b) % MOD;
}

/// 自定义类型以及hash
struct UVK {
    ll u;
    ll v;
    ll k;
    UVK(ll u_, ll v_, ll k_) : u(u_), v(v_), k(k_) {}
    bool operator< (const UVK& rhs) const {
        return (u < rhs.u) || (u == rhs.u && v < rhs.v) || (u == rhs.u && v == rhs.v && k < rhs.k);
    }
};

struct UVKHash {
    ll operator() (const UVK& uvk) const {
        return ((hash<int>()(uvk.u) ^ (hash<int>()(uvk.v) << 1)) >> 1) ^ (hash<int>()(uvk.k) << 1);
    }
};

struct UVKComparator {
    bool operator() (const UVK& x, const UVK& y) const {
        return x.u == y.u && x.v == y.v && x.k == y.k;
    }
};


/// main函数
int main() {
    ll N;
    cin >> N;
    ll x;
    cin >> x;
    ll max = x;
    ll ans = 1;
    for (int i = 1; i < N; ++i) {
        cin >> x;
        if (x >= max) {
            max = x;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}