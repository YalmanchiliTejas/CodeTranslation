#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define ln '\n'
const double PI = acos(-1.0);
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T, typename U, typename F, typename G, typename H>
struct LazySegmentTree {
    T unitynode;
    U unitylazy;
    F f;
    G g;
    H h;
    int N;
    int height;
    vector<T> node;
    vector<U> lazy;

    LazySegmentTree(F f, G g, H h, T unitynode, U unitylazy) : f(f), g(g), h(h), unitynode(unitynode), unitylazy(unitylazy) {}

    void init(int sz) {
        N = 1;
        height = 0;
        while (N < sz) {
            N *= 2;
            ++height;
        }
        node.assign(2*N,unitynode);
        lazy.assign(2*N,unitylazy);
    }

    void set(int k, const T &val) {node[k+N] = val;}

    void build() {
        for (int i = N-1; i > 0; --i) {
            node[i] = f(node[i<<1|0],node[i<<1|1]);
        }
    }

    inline T reflect(int k) {
        return lazy[k] == unitylazy ? node[k] : g(node[k],lazy[k]);
    }

    void eval(int k) {
        if (lazy[k] == unitylazy) return;
        if (k < N) {
            lazy[k<<1|0] = h(lazy[k<<1|0],lazy[k]);
            lazy[k<<1|1] = h(lazy[k<<1|1],lazy[k]);
        }
        node[k] = reflect(k);
        lazy[k] = unitylazy;
    }

    inline void recalc(int k) {
        while (k >>= 1) {
            node[k] = f(reflect(k<<1|0),reflect(k<<1|1));
        }
    }

    // [l,r) (0-indexed)
    void update(int l, int r, U val) {
        if (l >= r) return;
        l += N; r += N-1;
        for (int i = height; i > 0; --i) {
            eval(l>>i);
            eval(r>>i);
        }
        int a = l; int b = r++;
        while (l < r) {
            if (l & 1) lazy[l] = h(lazy[l],val), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r],val);
            l >>= 1; r >>= 1;
        }
        recalc(a);
        recalc(b);
    }

    T get(int l, int r) {
        if (l >= r) return unitynode;
        l += N; r += N-1;
        for (int i = height; i > 0; --i) {
            eval(l>>i);
            eval(r>>i);
        }
        ++r;
        T vl = unitynode, vr = unitynode;
        while (l < r) {
            if (l & 1) vl = f(vl,reflect(l++));
            if (r & 1) vr = f(reflect(--r),vr);
            l >>= 1; r >>= 1;
        }
        return f(vl,vr);
    }

    T operator[](int x) {return reflect(x+N);}
};

/*
example
auto f=[](ll a, ll b) {return min(a,b);};
auto g=[](ll a, ll b) {return b;};
auto h=[](ll a, ll b) {return b;};
ll id1 = 1e18; ll id2 = -1;
LazySegmentTree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(f,g,h,id1,id2);
seg.init(N);
for (int i = 0; i < N; ++i) seg.set(i,(1LL<<31)-1);
seg.build();
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N,M; cin >> N >> M;
    set<pii> left, right;
    vector<int> L(M),R(M),A(M);
    rep(i,M) {
        int l,r,a; cin >> L[i] >> R[i] >> A[i];
        left.emplace(L[i],i);
    }

    auto f=[] (ll a, ll b) {return max(a,b);};
    auto g=[] (ll a, ll val) {return a+val;};
    auto h=[] (ll a, ll b) {return a+b;};
    const ll id1 = -1e18;
    const ll id2 = 0;
    LazySegmentTree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(f,g,h,id1,id2);
    seg.init(N+1);
    rep(i,N+1) seg.set(i,0);
    seg.build();

    for (int i = 1; i <= N; ++i) {
        while (!left.empty() && left.begin()->first==i) {
            seg.update(0,i,A[left.begin()->second]);
            right.emplace(R[left.begin()->second],left.begin()->second);
            left.erase(left.begin());
        }
        ll val = seg.get(0,i);
        seg.update(i,i+1,val);
        while (!right.empty()&&right.begin()->first==i) {
            seg.update(0,L[right.begin()->second],-A[right.begin()->second]);
            right.erase(right.begin());
        }
    }
    
    cout << seg.get(0,N+1) << ln;
}