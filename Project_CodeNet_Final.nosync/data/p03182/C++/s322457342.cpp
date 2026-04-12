#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())
#define po first.first
#define ri first.second
#define be second

struct segmentTreeLazy
{
    struct node
    {
        int val, lazy;
        void setLeaf(int idx) { val = 0; lazy = 0; }
        friend node operator+(const node &lhs, const node &rhs)
        {
            node res;
            res.val = max(lhs.val, rhs.val);
            res.lazy = 0;
            return res;
        }
        bool isLazy() { return (lazy != 0); }
        void applyUpdate(int upd)
        {
            val += upd;
            lazy += upd;
        }
        void resetLazy() { lazy = 0; }
        int query() { return val; }
    };

    int N;
    vector<node> st;
    segmentTreeLazy(int n) : N(n), st(4*N+5) {}

    void propagate(int u, int l, int r)
    {
        if(l != r)
        {
            st[2*u].applyUpdate(st[u].lazy);
            st[2*u+1].applyUpdate(st[u].lazy);
        }
        st[u].resetLazy();
    }

    void buildHelper(int u, int l, int r)
    {
        if(l == r)
        {
            st[u].setLeaf(l);
            return;
        }
        int m = (l+r)/2;
        buildHelper(2*u, l, m);
        buildHelper(2*u+1, m+1, r);
        st[u] = st[2*u] + st[2*u+1];
    }
    void build() { buildHelper(1, 1, N); }

    node queryHelper(int u, int l, int r, int i, int j)
    {
        if(l >= i && r <= j)
            return st[u];
        if(st[u].isLazy())
            propagate(u, l, r);
        int m = (l+r)/2;
        if(j <= m)
            return queryHelper(2*u, l, m, i, j);
        else if(i >= m+1)
            return queryHelper(2*u+1, m+1, r, i, j);
        else
            return queryHelper(2*u, l, m, i, j) + queryHelper(2*u+1, m+1, r, i, j);
    }
    int query(int i, int j) { return queryHelper(1, 1, N, i, j).query(); }

    void updateHelper(int u, int l, int r, int i, int j, int upd)
    {
        if(l >= i && r <= j)
        {
            st[u].applyUpdate(upd);
            return;
        }
        if(st[u].isLazy())
            propagate(u, l, r);
        int m = (l+r)/2;
        if(j <= m)
            updateHelper(2*u, l, m, i, j, upd);
        else if(i >= m+1)
            updateHelper(2*u+1, m+1, r, i, j, upd);
        else
        {
            updateHelper(2*u, l, m, i, j, upd);
            updateHelper(2*u+1, m+1, r, i, j, upd);
        }
        st[u] = st[2*u] + st[2*u+1];
    }
    void update(int i, int j, int upd) { if(i>j) return; updateHelper(1, 1, N, i, j, upd); }
};

vector<int> o[200005];
vector<pair<int,int>> e[200005];
segmentTreeLazy st(200005);

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int l, r, b;
        cin >> l >> r >> b;
        o[l].pb(b); e[r].pb({l, b});
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(auto &k: o[i])
            sum += k;
        st.update(i, i, st.query(1, i) + sum);
        for(auto &k: e[i])
            st.update(k.first, i-1, k.second), sum -= k.second;
        st.update(i, i, -sum);
    }
    cout << st.query(1, 200005) << endl;
}