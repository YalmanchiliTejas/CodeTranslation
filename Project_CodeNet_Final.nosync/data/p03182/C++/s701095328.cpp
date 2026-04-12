#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N, M;
vector<P> score[200100];

struct lazysegtree {
    int size;
    vector<int> node, lazy;
    
    lazysegtree(int n) {
        size = 1;
        while (size<n) size *= 2;
        node.resize(2*size-1);
        lazy.resize(2*size-1);
    }
    
    void eval(int k) {
        node[k] += lazy[k];
        if (k<size-1) {
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }
    
    void update(int a, int b, int x, int k, int l, int r) {
        eval(k);
        if (b<=l || r<=a) return;
        if (a<=l && r<=b) {
            lazy[k] += x;
            eval(k);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
    
    int query(int a, int b, int k, int l, int r) {
        eval(k);
        if (b<=l || r<=a) return -1000000000000000;
        if (a<=l && r<=b) return node[k];
        int vl = query(a, b, 2*k+1, l, (l+r)/2);
        int vr = query(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

    void add(int a, int b, int x) {
        update(a, b, x, 0, 0, size);
    }
    
    int get(int a, int b) {
        return query(a, b, 0, 0, size);
    }
};

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, M) {
        int l, r, a; cin >> l >> r >> a;
        score[r].pb(P(l, a));
    }
    
    lazysegtree lst(N+1);
    for (int i=1; i<=N; i++) {
        int su = 0;
        rep(j, score[i].size()) su += score[i][j].second;
        lst.add(i, i+1, lst.get(0, i)+su);
        rep(j, score[i].size()) {
            P p = score[i][j];
            int l = p.first, a = p.second;
            lst.add(l, i, a);
        }
    }
    cout << lst.get(0, N+1) << endl;
}