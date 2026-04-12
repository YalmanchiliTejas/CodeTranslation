#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }

//UnionFind 木
// T (typename) : グラフの頂点を表す型, (int)parent, (int)size を持つ必要あり
template <typename T>
struct UnionFind {
    vector<T> &u;
    UnionFind(vector<T> &u) : u(u) {
        for (int i = 0; i < u.size(); i++) {
            u[i].parent = i;
        }
    }
    int root(int x) {
        if (x < 0 || u.size() <= x)
            return -1;
        else if (x == u[x].parent)
            return x;
        else
            return u[x].parent = root(u[x].parent);
    }
    bool connect(int a, int b) {
        a = root(a), b = root(b);
        if (a == b || a < 0 || b < 0) return false;
        { /* do something */
        }
        u[b].parent = a;
        return true;
    }
    // O(u.size())
    void count(map<int, int> &ret) {
        for (int i = 0; i < u.size(); i++) {
            int tmp = u[i].parent;
            if (!ret.count(tmp)) {
                ret[tmp] = 0;
            }
            ret[tmp]++;
        }
    }
};

template <typename Edge>
void Kruskal(vector<Edge> &edge, int N, vector<Edge> &ans) {
    struct Node {
        int parent;
    };
    rev_priority_queue<Edge> q;
    vector<Node> node(N);
    UnionFind<Node> uf(node);
    for (auto e : edge) q.push(e);
    while (!q.empty()) {
        Edge e = q.top();
        q.pop();
        if (uf.root(e.v1) != uf.root(e.v2)) {
            uf.connect(e.v1, e.v2);
            ans.push_back(e);
        }
    }
}

struct Edge {
    int v1, v2;
    i64 cost;
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<i64, int>> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        i64 x, y;
        cin >> x >> y;
        X[i] = {x, i}, Y[i] = {y, i};
    }
    sort(WHOLE(X)), sort(WHOLE(Y));
    vector<Edge> e;
    for(int b = 0; b < 2; b++) {
        for(int i = 0; i < N - 1; i++) {
            auto s = X[i], t = X[i + 1];
            e.push_back({s.second, t.second, t.first - s.first});
        }
        swap(X, Y);
    }
    vector<Edge> span;
    i64 ans = 0;
    Kruskal(e, N, span);
    for(auto x : span) ans += x.cost;
    cout << ans << endl;
    return 0;
}