#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , "; logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

template<class T, class M>
class abstract_lazy_segtree{
    public:

    int n; vector<T> data; vector<M> lazy;
    T id; M def;
    function<T(T,T)> op;
    function<T(T,M)> upd;
    function<M(M,M)> merge;
    function<M(M,int)> p;

    abstract_lazy_segtree(size_t _n, T _id, M _def,
    function<T(T,T)> _op, function<T(T,M)> _upd, function<M(M,M)> _merge,
    function<M(M,int)> _p = [](M a, int b){ return a; })
    : id(_id), def(_def), op(_op), upd(_upd), merge(_merge), p(_p){
        n = 1;
        while(n < _n) n *= 2;
        data = vector<T>(2*n-1, id);
        lazy = vector<M>(2*n-1, def);
    }

    void eval(int k, int l, int r){
        if(lazy[k] == def) return;
        if(r-l>1){
            lazy[k*2+1] = merge(lazy[k*2+1], lazy[k]);
            lazy[k*2+2] = merge(lazy[k*2+2], lazy[k]);
        }
        data[k] = upd(data[k], lazy[k]);
        lazy[k] = def;
    }
    void update(int a, int b, M x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            eval(k, l, r);
            lazy[k] = merge(lazy[k],p(x, r-l));
            eval(k, l, r);
        }
        else{
            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            data[k] = op(data[2*k+1], data[2*k+2]);
        }
    }
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(b <= l || r <= a) return id;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T ll = query(a, b, k*2+1, l, (l+r)/2);
        T rr = query(a, b, k*2+2, (l+r)/2, r);
        return op(ll,rr);
    }

    T operator[](int i){
        return data[i+n-1];
    }
};

struct segment{
    lint l, a;
};

int main(){
    int n, m; cin >> n >> m;
    vector<segment> vs[MAX];
    rep(i, m){
        lint l,r,a; cin>>l>>r>>a;
        vs[r].push_back(segment{l-1, a});
    }

    abstract_lazy_segtree<lint, lint> st(n, 0, 0,
    [](lint x, lint y){ return max(x, y); },
    [](lint x, lint y){ return x+y; },
    [](lint x, lint y){ return x+y; });

    rep(i, n){
        lint x = max(0LL, st.query(0, i));
        st.update(i, i+1, x);
        for(auto s : vs[i+1]){
            st.update(s.l, i+1, s.a);
        }
    }

    out(max(st.query(0, n+1),0LL));
}
