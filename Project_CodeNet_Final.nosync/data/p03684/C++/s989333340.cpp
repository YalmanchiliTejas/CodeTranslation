#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

struct UF {
    vector<int> a;
    UF(int n) {
        a.resize(n, -1);
    }
    int root(int i) {
        return a[i] < 0 ? i : a[i] = root(a[i]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        x=root(x), y=root(y);
        if (x==y) return;
        if (-a[x] < -a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
    }
};

struct edge {
    int c, u, v;
    edge(int c, int u, int v) : c(c), u(u), v(v) {};
};

bool operator<(const edge& a, const edge& b) {
    return a.c < b.c;
}

int main()
{
    int n; cin >> n;
    vector<pii> A, B;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        A.push_back(pii(a, i));
        B.push_back(pii(b, i));
    }
    
    sort(begin(A), end(A));
    sort(begin(B), end(B));
    
    vector<edge> edges;

    for (int i = 0; i < n - 1; ++i) {
        edge e1 = edge(abs(A[i].first - A[i + 1].first), A[i].second, A[i+1].second);
        edge e2 = edge(abs(B[i].first - B[i + 1].first), B[i].second, B[i+1].second);

        edges.push_back(e1);
        edges.push_back(e2);
    }

    sort(begin(edges), end(edges));
    
    UF uf(n);

    long long ans = 0;
    
    for (int i = 0; i < (int)edges.size(); ++i) {
        if (uf.same(edges[i].u, edges[i].v)) continue;
        
        ans += edges[i].c;
        
        uf.unite(edges[i].u, edges[i].v);
    }
    
    cout << ans << endl;
}
