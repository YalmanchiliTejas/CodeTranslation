#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

class SegTree {
    public:
    struct node {
        int l, r;
        ll val, lazy = 0;
        void reset(int l, int r, ll val = 0, ll lazy = 0) {
            this -> l = l;
            this -> r = r;
            this -> val = val;
            this -> lazy = lazy;
        }

        void update_lazy(ll lazy) {
            this -> lazy += lazy;
        }

        bool check_lazy() {
            return this -> lazy;
        }
    };

    vector <node> seg;

    SegTree(int n) {
        seg.resize(1 << (33-__builtin_clz(n)));
        build(1, n);
    }

    void build(int l, int r, int i = 1) {
        if (l == r) {
            seg[i].reset(l, l);
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2*i);
        build(m + 1, r, 2*i + 1);
        merge(i);
    }

    void merge(int i) {
        merge(i, 2*i, 2*i + 1);
    }

    void merge(int p, int l, int r) {
        merge(seg[p], seg[l], seg[r]);
    }

    void merge(node& p, node l, node r) {
        p.reset(l.l, r.r, max(l.val + l.lazy, r.val + r.lazy), 0);
    }

    void push(int i) {
        if (seg[i].l != seg[i].r) {
            ll lazy = seg[i].lazy;
            seg[2*i].update_lazy(lazy);
            seg[2*i + 1].update_lazy(lazy);
            merge(i);
        }
        else {
            // fix laziness in leaves, not necessary OCD.
            seg[i].val = seg[i].val + seg[i].lazy;
            seg[i].lazy = 0;
        }
    }

    void _qry (int l, int r, int i = 1) {
        node& a = seg[i];
        if (a.l > r || a.r < l) return;
        if (a.l >= l and a.r <= r) {
            merge(0, 0, i);
            return;
        }
        
        if (seg[i].check_lazy()) {
            push(i);
        }
        _qry(l, r, 2*i);
        _qry(l, r, 2*i + 1);
    }

    ll qry (int l, int r) {
        if (l > r)
            return 0;
        
        ll minm = 0;
        
        node& res = seg[0];
        res.reset(0, 0, minm);
        _qry(l, r);
        return max(res.val + res.lazy, 0ll);
    }

    void range_update(int l, int r, ll lazy, int i = 1) {
        node& a = seg[i];

        if (a.l > r || a.r < l) return;

        if (a.l >= l and a.r <= r) {
            seg[i].update_lazy(lazy);
            return;
        }

        if (a.check_lazy()) {
            push(i);
        }

        range_update(l, r, lazy, 2*i);
        range_update(l, r, lazy, 2*i + 1);
        merge(i);
    }

    void set_pos(int pos, ll val, int i = 1) {
        node& a = seg[i];

        if(a.l == a.r) {
            a.reset(a.l, a.r, val);
            return;
        }

        if(a.check_lazy()) {
            push(i);
        }
        
        set_pos(pos, val, 2*i + (pos > (a.l + a.r) / 2));
        merge(i);
    }
};

struct range {
    int l, r, a;
    
    range(int l, int r, int a) : l(l), r(r), a(a) {};
    
    bool operator < (const range& b) {
        return r < b.r;
    }
};

int main() {
    nfs
    int i, j, n, m, l, r, a;
    vector <range> inp;
    
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> l >> r >> a;
        inp.pb({l, r, a});
    }
    SegTree seg(n);

    sort(inp.begin(), inp.end());
    for (i = 1, j = 0; i <= n; i++) {
        seg.set_pos(i, seg.qry(1, i-1));
        
        while (j < m and inp[j].r == i){
            range& cur = inp[j];
            seg.range_update(cur.l, cur.r, cur.a);
            j++;
        }
    }
    cout << seg.qry(1, n);
}