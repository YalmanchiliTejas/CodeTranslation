#ifdef loc
    #include "loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(a) int(a.size())

const ll inf = 2e18;

struct node { /*{{{*/
    public:
    ll mx, ex;
    node() {
        mx = -inf;
        ex = 0;
    }
    void merge(node& l, node& r) {
        mx = max(l.mx, r.mx);
    }
    void split(node& l, node& r) {
        if(ex) {
            l.mx += ex;
            r.mx += ex;
            l.ex += ex;
            r.ex += ex;
            ex = 0;
        }
    }
};/*}}}*/
template<class node>
    class segtree { /*{{{*/
    template<bool b>class param {};
    inline void spltdwn(int idx, param<true>) {
        splt(idx);
    }
    inline void splt(int idx) { /*{{{*/
        idx >>= 1;
        if(idx > 0) {
            splt(idx);
        }
        tree[idx].split(tree[idx << 1], tree[(idx << 1) | 1]);
    }/*}}}*/
    inline void spltdwn(int, param<false>) {};
    inline void split(node& a, node& b, node& c, param<true>) {
        return a.split(b, c);
    }
    inline void split(node&, node&, node&, param<false>) {}
    template<typename t, void (t::*)(t&, t&)> class T {};
    template<typename t> static char test(T<t, &t::split> *) {
        return 0;
    }
    template<typename t> static long double test(...) {
        return 0;
    }
    int u, v;
    node query(int root, int left_range, int right_range) { /*{{{*/
        if(u <= left_range && right_range <= v) {
            return tree[root];
        }
        int mid = (left_range + right_range) >> 1,
            l = root << 1,
            r = l | 1;
        if(has_split) {
            split(tree[root], tree[l], tree[r], param<has_split>());
        }
        node res;
        if(u >= mid) {
            res = query(r, mid, right_range);
        } else if(v <= mid) {
            res = query(l, left_range, mid);
        } else {
            node n1 = query(l, left_range, mid),
                 n2 = query(r, mid, right_range);
            res.merge(n1, n2);
        }
        if(has_split) {
            tree[root].merge(tree[l], tree[r]);
        }
        return res;
    }/*}}}*/
    template<void(*fn)(node&)>
    void local_update(int root, int left_range, int right_range) { /*{{{*/
        if(u <= left_range && right_range <= v) {
            return fn(tree[root]);
        }
        int mid = (left_range + right_range) >> 1,
            l = root << 1,
            r = l | 1;
        if(has_split) {
            split(tree[root], tree[l], tree[r], param<has_split>());
        }
        if(v > mid) {
            local_update<fn>(r, mid, right_range);
        }
        if(u < mid) {
            local_update<fn>(l, left_range, mid);
        }
        tree[root].merge(tree[l], tree[r]);
    }/*}}}*/
    void mrgup(int idx) { /*{{{*/
        idx >>= 1;
        while(idx > 0)
            tree[idx].merge(tree[idx << 1], tree[(idx << 1) | 1]),
                 idx >>= 1;
    }/*}}}*/
    public:
    static bool const has_split = (sizeof(test<node>(0)) == sizeof(char));
    int N;
    int leftmost_leaf, rightmost_leaf;
    node *tree;
    node identity;
    segtree() {
        tree = 0;
    }
    ~segtree() {
        if(tree) {
            delete[] tree;
        }
    }
    void init(int n, const node a[], const node& identity) { /*{{{*/
        if(tree) {
            delete[] tree;
        }
        this->identity = identity;
        N = 0;
        while((1 << N) < n) {
            N++;
        }
        leftmost_leaf = 1 << N;
        rightmost_leaf = leftmost_leaf << 1;
        tree = new node[rightmost_leaf];
        for(int i = 0; i < n; i++) {
            tree[i + leftmost_leaf] = a[i];
        }
        for(int i = n + leftmost_leaf; i < rightmost_leaf; i++) {
            tree[i] = identity;
        }
        for(int i = leftmost_leaf - 1; i; i--) {
            tree[i].merge(tree[i << 1], tree[(i << 1) | 1]);
        }
    }/*}}}*/
    node query(int u, int v) { //[u,v]/*{{{*/
        this->u = u + leftmost_leaf;
        this->v = v + leftmost_leaf + 1;
        return query(1, leftmost_leaf, rightmost_leaf);
    }/*}}}*/
    node query(int u) { //faster version of query(u,u)/*{{{*/
        //indexing starts from 0
        u += leftmost_leaf;
        spltdwn(u, param<has_split>());
        return tree[u];
    }/*}}}*/
    template<void(*fn)(node&)>
    void update(int u, int v) { /*{{{*/
        //0-indexed
        this->u = u + leftmost_leaf;
        this->v = v + leftmost_leaf + 1;
        return local_update<fn>(1, leftmost_leaf, rightmost_leaf);
    }/*}}}*/
    template<void(*fn)(node&)>
    void update(int u) { //faster version of update(u,u)/*{{{*/
        //indexing starts from 0
        u += leftmost_leaf;
        spltdwn(u, param<has_split>());
        fn(tree[u]);
        mrgup(u);
    }/*}}}*/
    void split_down(int leaf_idx) { /*{{{*/
        spltdwn(leaf_idx + leftmost_leaf, param<has_split>());
    }/*}}}*/
    void merge_up(int leaf_idx) { /*{{{*/
        mrgup(leaf_idx + leftmost_leaf);
    }/*}}}*/
    bool is_leaf(int tree_idx) {
        return tree_idx >= leftmost_leaf;
    }
    int binary_search(node k) { /*{{{*/
        //search the last place i, such that merge( everyting to the left of i(including i) ) compares less than k
        int root = 1;
        node n = identity;
        //identity satisfies merge(identity,y) = merge(y,identity) = y for all y.
        assert(!(k < identity));
        while(!is_leaf(root)) {
            int left_child = root << 1,
                right_child = left_child | 1;
            if(has_split) {
                split(tree[root], tree[left_child], tree[right_child], param<has_split>());
            }
            node m;
            m.merge(n, tree[left_child]);
            if(m < k) { //go to right side
                n = m;
                root = right_child;
            } else {
                root = left_child;
            }
        }
        node m;
        m.merge(n, tree[root]);
        mrgup(root);
        if(m < k) {
            return root - leftmost_leaf;
        } else {
            return root - 1 - leftmost_leaf;
        }
    }/*}}}*/
};/*}}}*/

ll ex;
void upd(node& n) {
    n.mx += ex;
    n.ex += ex;
}


const int N = 400065;
vector<pair<int, ll>> vals[N], vale[N];

ll f[N], g[N];
node sn[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(m-- > 0) {
        int l, r, v;
        cin >> l >> r >> v;
        vals[l].emplace_back(make_pair(r, v));
        vale[r].emplace_back(make_pair(l, v));
    }
    segtree<node> st;
    rep(i, 0, n + 1) {
        sn[i].mx = sn[i].ex = 0;
    }
    sn[n + 1].mx = -inf;
    sn[n + 1].ex = 0;
    st.init(n + 1, sn, sn[n + 1]);
    rep(i, 1, n + 1) {
        rep(j, vale[i - 1].begin(), vale[i - 1].end()) {
            ex = -j->second;
            st.update<&upd>(0, j->first - 1);
        }
        rep(j, vals[i].begin(), vals[i].end()) {
            ex = j->second;
            st.update<&upd>(0, i - 1);
        }
        f[i] = st.query(0, i - 1).mx;
        ex = f[i];
        st.update<&upd>(i, i);
    }
    ll ans = 0;
    rep(i, 1, n + 1) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}

/*
f[i] = max score for length i when last one is at i.
ans = max(f[i]);
f[i] = f[j] + scores for intervals that l[k]>j && r[k]>=i

when processing i+1 - intervals that end at i [x,i] -a[v] from [0,x-1];
intervals that start i+1 [i+1,x] +a[v] to [0,x].
*/