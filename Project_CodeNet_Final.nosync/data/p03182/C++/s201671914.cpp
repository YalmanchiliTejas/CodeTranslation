#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;
using ll = long long;
using DBL = double;
using VI = vector<int>;
using VD = vector<DBL>;
using VVI = vector<VI>;
using VVD = vector<VD>;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i,n) FOR(i,0,n)
#define SZ(a) ((int)((a).size()))
#define ALL(x) (x).begin(), (x).end()
#define SET(a,v) memset((a), (v), sizeof(a))
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//#define trace(...) {__f(#__VA_ARGS__, __VA_ARGS__);}
//template<typename Arg> void __f(const char* name, Arg&& arg) {
//  cerr << name << " = " << arg << std::endl;
//} template <typename Arg1, typename... Args>
//void __f(const char* names, Arg1&& arg1, Args&&... args) {
//  const char* comma = strchr(names + 1, ',');
//  cerr.write(names, comma - names) << " = " << arg1<<" | ";__f(comma+1, args...); }
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; // OST: find_by_order, order_of_key
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//#pragma GCC optimize("Ofast")
//optimize("unroll-loops")
//target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///*** RNGS ***/
//SEED=chrono::steady_clock::now().time_since_epoch().count();
//// or high_resolution_clock
//mt19937 rng(SEED); /*or*/ random_device rd; mt19937 rng(rd());
//uniform_int_distribution<> dis(MIN, MAX);// usage: dis(rng)
//struct chash {int operator()(int x) const {return x^SEED;}};
//gp_hash_table<int,int,chash>m;//use cc if very less updates
///*** FAST IO ***/
//inline int scan(){ bool y=0; int x=0; char c=getchar_unlocked();
//while(c<'0'||c>'9'){ if(c=='-')y=1; c=getchar_unlocked();}
//while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar_unlocked();}
//return y?-x:x; }

const int MAXN = 200010;
const long long inf = 1e18;
int l[MAXN], r[MAXN], a[MAXN];
vector<int> u[MAXN];
int n, m;

class node {
public:
    long long maxVal;
    long long diff;
    long long val;
    node() {
        maxVal = 0;
        val = -inf;
        diff = 0;
    }
} tree[4*MAXN];

void removelazy(int x, int l, int r) {
    if(tree[x].val == -inf and tree[x].diff == 0) return;
    tree[x].maxVal = max(tree[x].maxVal + tree[x].diff, tree[x].val);
    if(l != r) {
        tree[2*x].val += tree[x].diff;
        tree[2*x].diff += tree[x].diff;
        tree[2*x].val = max(tree[2*x].val, tree[x].val);

        tree[1+(2*x)].val += tree[x].diff;
        tree[1+(2*x)].diff += tree[x].diff;
        tree[1+(2*x)].val = max(tree[1+(2*x)].val, tree[x].val);
    }
    tree[x].val = -inf;
    tree[x].diff = 0;
}

void upd(int x, int l, int r, int p, int q, long long v1, long long v2) {
    removelazy(x, l, r);
    if(r < p or q < l) return;
    if(p <= l and r <= q) {
        tree[x].val = v1;
        tree[x].diff = v2;
        removelazy(x, l, r);
        return;
    }
    int m = ((l+r)/2);
    upd(2*x, l, m, p, q, v1, v2);
    upd((2*x)+1, 1+m, r, p, q, v1, v2);
    tree[x].maxVal = max(tree[2*x].maxVal, tree[2*x+1].maxVal);
}

long long query(int x, int l, int r, int p) {
    removelazy(x, l, r);
    if(l == r) {
        assert(l == p);
        return tree[x].maxVal;
    }
    int m = ((l+r)/2);
    if(p <= m) return query((2*x), l, m, p);
    else return query((2*x)+1, 1+m, r, p);
}

int main() {
    #ifdef LOCAL_EXEC
//    freopen("sample.in", "r", stdin);
//    freopen("sample.out", "w", stdout);
    #else
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #endif
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        cin >> l[i] >> r[i] >> a[i];
        u[r[i]].PB(i);
    }
    for(int pos=n; pos>=0; --pos) {
        if(pos != n) upd(1, 0, n, 0, pos, query(1, 0, n, pos+1), 0);
        for(auto&i: u[pos]) {
            upd(1, 0, n, l[i], pos, -inf, a[i]);
        }
    }
    cout << query(1, 0, n, 0) << endl;
    return 0;
}
