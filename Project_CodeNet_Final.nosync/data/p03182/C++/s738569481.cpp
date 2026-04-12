/*input
3 4
1 3 100
1 1 -10
2 2 -20
3 3 -30
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=1e6+1;
 ll MOD=1e9+7;
const ld PI=2*acos(0);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
int add(int a,int b){
    return (a+b)%MOD;
}
int mult(int a,int b){
    return (ll)a*b%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}

// default code end
const int N = 2e5 + 9;
const ll oo = 1e18;
ll t[N<<2];
ll pushing[N<<2];
struct SegmentTree {

    SegmentTree() {
        fill(t, t + (N << 2), 0);
        fill(pushing, pushing + (N << 2), 0);
    }

    void push(int v) {
        pushing[v << 1] += pushing[v];
        t[v << 1] += pushing[v];
        pushing[v << 1 | 1] += pushing[v];
        t[v << 1 | 1] += pushing[v];
        pushing[v] = 0;
    }

    void upd(int v, int tl, int tr, int l, int r, ll inc) {
        if (l > r) return;
        if (tl == l && tr == r) {
            t[v] += inc;
            pushing[v] += inc;
            return;
        }
        push(v);
        int tm = tl + tr >> 1;
        upd(v << 1, tl, tm, l, min(tm, r), inc);
        upd(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r, inc);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -oo;
        if (tl == l && tr == r) {
            return t[v];
        }
        push(v);
        int tm = tl + tr >> 1;

        return max(
                get(v << 1, tl, tm, l, min(tm, r)),
             get(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
};

int n, m;

int lf[N], rf[N];
ll a[N];
ll dp[N];

vector<int> st[N], fin[N];

int main(){
    cin >> n >> m;
    REP (i, m) {
        cin >> lf[i] >> rf[i] >> a[i];
        st[lf[i]].push_back(i);
        fin[rf[i]].push_back(i);
    }
    SegmentTree tree;
    for (int i = 1; i <= n; ++i) {
        for (auto ind : st[i]) {
            tree.upd(1, 0, n, 0, i - 1, a[ind]);
        }
        dp[i] = tree.get(1, 0, n, 0, i - 1);
        tree.upd(1, 0, n, i, i, dp[i]);
        for (auto ind : fin[i]) {
            tree.upd(1, 0, n, 0, lf[ind] - 1, -a[ind]);
        }
    }
    cout << *max_element(dp,dp+n+1);
}
