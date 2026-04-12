#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>


typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
template <typename T>
T mod(T a, T b) { return ((a % b) + b) % b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }



template <typename T, typename OP>
class LazySegmentTree {
 public:
    using MERGE = function<T(T,T)>;
    using APPLY = function<T(T,OP)>;
    using MERGE_OP = function<OP(OP,OP)>;

    MERGE merge_data_func;
    APPLY apply_lazy_func;
    MERGE_OP merge_lazy_func;
    T elem_ident;
    OP op_ident;
    std::vector<T> data;
    std::vector<OP> lazy;
    int n, height;

    LazySegmentTree(MERGE f, APPLY g, MERGE_OP h, T elem_ident, OP op_ident)
        : merge_data_func(f), apply_lazy_func(g), merge_lazy_func(h),
          elem_ident(elem_ident), op_ident(op_ident) {
    }

    void init(int n_temp) {
        n = 1; height = 0;
        while (n < n_temp) { n <<= 1; ++height; }
        data.assign(2*n, elem_ident);
        lazy.assign(2*n, op_ident);
    }

    void build(const std::vector<T> &v){
        int n_temp = v.size();
        init(n_temp);
        std::copy(v.begin(), v.end(), data.begin()+n);
        for (int i=n-1; i>0; --i) {
            data[i] = merge_data_func(data[(i << 1)|0], data[(i << 1)|1]);
        }
    }

    inline T reflect_lazy(int k){
        if (lazy[k] == op_ident) {
            return data[k];
        } else {
            T applied = apply_lazy_func(data[k], lazy[k]);
            return applied;
        }
    }

    inline void eval(int k){
        if (lazy[k] == op_ident) return;
        lazy[(k << 1)|0] = merge_lazy_func(lazy[(k << 1)|0], lazy[k]);
        lazy[(k << 1)|1] = merge_lazy_func(lazy[(k << 1)|1], lazy[k]);
        data[k] = reflect_lazy(k);
        lazy[k] = op_ident;
    }

    inline void eval_down(int k) {
        for (int i=height; i>0; --i) {
            eval(k >> i);
        }
    }

    inline void merge_up(int k) {
        while (k >>= 1) {
            data[k] = merge_data_func(reflect_lazy((k << 1)|0), reflect_lazy((k << 1)|1));
        }
    }

    void update(int a, int b, OP x) {
        eval_down(a += n);
        eval_down(b += n-1);
        for (int l=a,r=b+1; l<r; l>>=1,r>>=1) {
            if (l&1) { lazy[l] = merge_lazy_func(lazy[l], x); ++l; }
            if (r&1) { --r; lazy[r] = merge_lazy_func(lazy[r], x); }
        }
        merge_up(a);
        merge_up(b);
    }

    void set_val(int a, T x) {
        eval_down(a += n);
        data[a] = x;
        lazy[a] = op_ident;
        merge_up(a);
    }

    T query(int a, int b) {
        eval_down(a += n);
        eval_down(b += n-1);
        T vl = elem_ident, vr = elem_ident;
        for (int l=a,r=b+1; l<r; l>>=1,r>>=1) {
            if (l & 1) {
                vl = merge_data_func(vl, reflect_lazy(l++));
            }
            if (r & 1) {
                vr = merge_data_func(reflect_lazy(--r), vr);
            }
        }
        T merged = merge_data_func(vl, vr);
        return merged;
    }

    void desc() {
    }
};


ll solve(int N, int M, vi& l, vi& r, vi& a) {
    vvi segment(N);
    rep(i,M) segment[ r[i] ].pb(i);

    auto f = [](ll a, ll b){ return max(a,b); };
    auto h = [](ll a, ll b){ return a+b; };

    LazySegmentTree<ll,ll> st(f, h, h, 0, 0);
    st.build(vll(N+2, 0));
    st.desc();

    rep(i,N) {
        ll left = max(0LL, st.query(0, i));

        st.update(i, i+1, left);
        for (int j: segment[i]) {
            st.update(l[j], r[j]+1, a[j]);
        }
        st.desc();
    }
    return max(0LL, st.query(0, N+1));
}

int main() {
    int N, M; scanf("%d%d", &N, &M);
    vi l(M), r(M), a(M);
    rep(i,M) {
        scanf("%d%d%d", &l[i], &r[i], &a[i]);
        --l[i]; --r[i];
    }
    cout << solve(N,M,l,r,a) << endl;
    return 0;
}
