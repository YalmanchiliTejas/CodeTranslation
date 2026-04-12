#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define cps CLOCKS_PER_SEC
#define tests(t) int t; cin >> t; while(t--)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
#define eb emplace_back
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define fi first
#define se second
#define mt make_tuple
#define pqueue priority_queue
#define bitcount(x) __builtin_popcount(x)
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << '(' << p.fi << ", " << p.se << ')'; }

template<typename T>
void printv(const T& v) { for(auto i : v) cerr << i << ' '; cerr << '\n'; }

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

//Returns no. of values x for which ceil(n / x) == y (y must be > 1).
inline ll CC(ll n, ll y) { return iceil(n, y-1) - iceil(n, y); }

//Returns no. of values x for which floor(n / x) == y
inline ll FF(ll n, ll y) { return n / y - n / (y+1); }

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }

#define N 200005
#define int ll
// #define trace(...) 42

int n, m, dp[N];
int L[N], R[N], a[N];
vpii adj[N];

struct ans{
    //val: Value at the node in the original st
    //lazy: Value at the node in the lazy st
    int val, lazy;
    ans(int val=0, int lazy=0)
        :val(val), lazy(lazy){}
};

ans st[N<<2];

inline ans op(ans u, ans v) {
    ans w;
    w.val = max(u.val, v.val);
    return w;
}

inline void propagate(int i, int l, int r)
{
    st[i].val += st[i].lazy;
    int lc = (i<<1), rc = (i<<1)|1;
    if(l != r){
        st[lc].lazy += st[i].lazy,\
        st[rc].lazy += st[i].lazy;
    }
    st[i].lazy = 0;
}

void build(int i, int l, int r)
{
    if(l == r){
        st[i].val = a[l];
    }
    else{
        int lc = (i<<1) , rc = (i<<1)|1 , m = (l+r)>>1;
        build(lc, l, m);
        build(rc, m+1, r);
        st[i] = op(st[lc], st[rc]);
    }
}

void update(int ql, int qr, int x, int i, int l, int r)
{
    propagate(i, l, r);

    int m = (l + r) >> 1;
    int lc = i << 1, rc = (i << 1) | 1;
    
    if(ql <= l && qr >= r){
        st[i].lazy = x;
        propagate(i, l, r);
        return;
    }
    
    if(qr < l || ql > r)
        return;
    else{
        update(ql, qr, x, lc, l, m);
        update(ql, qr, x, rc, m+1, r);
        st[i] = op(st[lc], st[rc]);
    }
}

ans query(int ql, int qr, int i, int l, int r)
{
    propagate(i, l, r);
    
    if(ql <= l && qr >= r)
        return st[i];

    // if(qr < l || ql > r)
    //  return ans();

    int m = (l + r) >> 1;
    int lc = i << 1, rc = (i << 1) | 1;

    if(qr <= m)
        return query(ql, qr, lc, l, m);
    if(ql > m)
        return query(ql, qr, rc, m+1, r);
    
    return op(query(ql,qr,lc,l,m), query(ql,qr,rc,m+1,r));
}

/*void print_tree()
{
    for(int i=0;i<n;i++)
        cerr << i << ' ' << query(i, i, 1, 0, n-1).val << ' ';
}*/

main()
{   
    #ifdef CP
        freopen("/home/tarun/Desktop/input.txt", "r", stdin);
     // freopen("/home/tarun/Desktop/output.txt", "w", stdout);
    #endif
    sync;
    clock_t clk = clock();
    cerr << "I will return...\n";

    cin >> n >> m;
    rep(i, 0, m) {
        cin >> L[i] >> R[i] >> a[i];
        adj[L[i]].pb({L[i]-1, a[i]});
        adj[R[i]+1].pb({L[i]-1, -a[i]});
    }

    int ans = 0;

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(auto p : adj[i]) {
            int idx, val; tie(idx, val) = p;
            update(0, idx, val, 1, 0, n);
            // trace(i, idx, val);
        }

        dp[i] = query(0, i-1, 1, 0, n).val;
        ans = max(ans, dp[i]);
        // trace(i, dp[i]);
        update(i, i, dp[i], 1, 0, n);
    }

    cout << ans << '\n';

    cerr << "...don't you ever hang your head.\n";
    cerr << "Time (in ms): " << (double)(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment
 

