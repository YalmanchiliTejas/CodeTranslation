#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
using P = pair<ll, pair<int, int>>;

class SkewHeap
{
private:
    struct Node {
        using T = P;
        using Ptr = shared_ptr<Node>;
        Node(const T& value) : left{}, right{}, value{value} {}
        Ptr left, right;
        T value;
        static Ptr meld(Ptr a, Ptr b)
        {
            if (a == nullptr) {
                return b;
            } else if (b == nullptr) {
                return a;
            }

            if (a->value > b->value) {
                swap(a, b);
            }
            a->right = meld(a->right, b);
            swap(a->left, a->right);
            return (a);
        }
    };
    Node::Ptr root;

public:
    using T = Node::T;
    SkewHeap() : root{} {}
    bool empty() const { return root == nullptr; }
    void push(const T& value) { root = Node::meld(root, make_shared<Node>(value)); }
    const T& top() const { return root->value; }
    void pop() { root = Node::meld(root->left, root->right); }
    void meld(SkewHeap h) { root = Node::meld(root, h.root); }
};

class DisjointSets
{
public:
    DisjointSets(const int v) : parent(v), rank(v, 0) { iota(parent.begin(), parent.end(), 0); }
    bool same(const int a, const int b) { return find(a) == find(b); }
    int find(const int a) { return (parent[a] == a ? a : parent[a] = find(parent[a])); }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        rank[a] += rank[b];
        parent[b] = a;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

struct Graph {
    using T = pair<ll, int>;
    Graph(const int v) : V{v}, edge(v) {}
    struct Edge {
        Edge(const int from, const int to, const T cost) : from{from}, to{to}, cost{cost} {}
        const int from;
        const int to;
        const T cost;
    };
    void addEdge(const int from, const int to, const T cost) { edge[from].push_back(Edge{from, to, cost}); }
    const int V;
    vector<vector<Edge>> edge;
};

ll dfs(const Graph& g, const int s, vector<SkewHeap>& heap, DisjointSets& uf, vector<bool>& used, vector<ll>& a)
{
    used[s] = true;
    for (const auto& e : g.edge[s]) {
        if (not used[e.to]) {
            const ll w = dfs(g, e.to, heap, uf, used, a);
            a[e.cost.second] = w == -1 ? -1 : w - e.cost.first;
            uf.unite(s, e.to);
            heap[s].meld(heap[e.to]);
        }
    }
    while (not heap[s].empty()) {
        const auto p = heap[s].top();
        if (uf.same(p.second.first, p.second.second)) {
            heap[s].pop();
        } else {
            break;
        }
    }
    if (heap[s].empty()) {
        return -1;
    }
    return heap[s].top().first;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<pair<P, int>> edge(M);
    DisjointSets uf(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--, b--;
        edge[i] = {{w, {a, b}}, i};
    }
    sort(edge.begin(), edge.end());
    Graph g(N);
    ll cost = 0;
    vector<SkewHeap> heaps(N);
    int E = 0;
    for (int i = 0; i < M; i++) {
        const int u = edge[i].first.second.first;
        const int v = edge[i].first.second.second;
        if (not uf.same(u, v)) {
            cost += edge[i].first.first;
            uf.unite(u, v);
            g.addEdge(u, v, {edge[i].first.first, edge[i].second});
            g.addEdge(v, u, {edge[i].first.first, edge[i].second});
            E++;
        } else {
            heaps[u].push(edge[i].first);
            heaps[v].push(edge[i].first);
        }
    }
    if (E < N - 1) {
        for (int i = 0; i < M; i++) {
            cout << "-1\n";
        }
        return 0;
    }
    vector<bool> used(N, false);
    vector<ll> ans(M, 0);
    DisjointSets uf1(N);
    dfs(g, 0, heaps, uf1, used, ans);
    for (int i = 0; i < M; i++) {
        cout << (ans[i] == -1 ? -1 : ans[i] + cost) << "\n";
    }
    return 0;
}

