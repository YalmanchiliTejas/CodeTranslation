//#pragma GCC target("avx2,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
constexpr char ln = '\n';
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
struct Fast_ios {Fast_ios() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20);};} fast_ios;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T, typename U, typename F, typename G, typename H>
struct LazySegmentTree {
  private:
    F op;
    G mapping;
    H composition;
    T e;
    U id;
    int _n, size ,log;
    vector<T> node;
    vector<U> lazy;

  public:
    LazySegmentTree() {}
    LazySegmentTree(const F& op, const G& mapping, const H& composition, T e, U id, int n)
                    : LazySegmentTree(op, mapping, composition, e, id, vector<T>(n, e)) {}
    LazySegmentTree(const F& op, const G& mapping, const H& composition, T e, U id, const vector<T>& v) 
                    : op(op), mapping(mapping), composition(composition), e(e), id(id),
                    _n(int(v.size())), log(0) {
                        while ((1<<log) < _n) log++;
                        size = 1 << log;
                        node = vector<T>(2 * size, e);
                        lazy = vector<U>(size, id);
                        for (int i = 0; i < _n; i++) node[size + i] = v[i];
                        for (int i = size - 1; i >= 1; i--) {
                            update(i);
                        }
                    }
    
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    // [l, r) (0-indexed)
    T get(int l, int r) {
        if (l >= r) return e;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        T sml = e, smr = e;
        while (l < r) {
            if (l & 1) sml = op(sml, node[l++]);
            if (r & 1) smr = op(node[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    T all_get() { return node[1]; }

    void apply(int p, U val) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p] = val == id ? node[p] : mapping(node[p], val);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, U val) {
        if (l >= r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, val);
                if (r & 1) all_apply(--r, val);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <typename C> 
    int max_right(int l, const C& check) {
        assert(0 <= l && l <= _n);
        assert(check(e));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        T sm = e;
        do {
            while (~l & 1) l >>= 1;
            if (!check(op(sm, node[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (check(op(sm, node[l]))) {
                        sm = op(sm, node[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, node[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <typename C>
    int min_left(int r, const C& check) {
        assert(0 <= r && r <= _n);
        assert(check(e));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        T sm = e;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!check(op(node[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (check(op(node[r], sm))) {
                        sm = op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(node[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    T operator[](int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return node[p];
    }

  private:
    
    void update(int k) { node[k] = op(node[2 * k], node[2 * k + 1]); }

    void all_apply(int k, U val) {
        node[k] = val == id ? node[k] : mapping(node[k], val);
        if (k < size) lazy[k] = composition(lazy[k], val);
    }

    void push(int k) {
        if (lazy[k] == id) return;
        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);
        lazy[k] = id;
    }  
};

/*
example
int N;
auto f=[](ll a, ll b) {return min(a,b);};
auto g=[](ll a, ll b) {return b;};
auto h=[](ll a, ll b) {return b;};
ll e = 1e18; ll id = -1;
LazySegmentTree<ll, ll, decltype(f), decltype(g), decltype(h)> seg(f,g,h,e,id,N);
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////

template <uint_fast64_t Modulus> 
struct ModInt {
    using u64 = uint_fast64_t;

    u64 a;

    constexpr ModInt(const long long x = 0) noexcept : a(x >= 0 ? x % Modulus : (Modulus - (-x) % Modulus) % Modulus) {}
    constexpr u64 &value() noexcept {return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr ModInt operator+(const ModInt rhs) const noexcept {return ModInt(*this) += rhs;}
    constexpr ModInt operator-(const ModInt rhs) const noexcept {return ModInt(*this) -= rhs;}
    constexpr ModInt operator*(const ModInt rhs) const noexcept {return ModInt(*this) *= rhs;}
    constexpr ModInt operator/(const ModInt rhs) const noexcept {return ModInt(*this) /= rhs;}
    constexpr ModInt operator^(const long long rhs) const noexcept {return ModInt(*this) ^= rhs;}
    constexpr bool operator==(const ModInt &rhs) const noexcept {return a == rhs.a;}
    constexpr bool operator!=(const ModInt &rhs) const noexcept {return a != rhs.a;}
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }
    constexpr ModInt &operator^=(long long exp) noexcept {
        ModInt rhs = a;
        a = 1;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }

    friend ostream &operator<<(ostream& os, const ModInt& rhs) noexcept {return os << rhs.a;}
    friend istream &operator>>(istream& is, ModInt& rhs) noexcept {long long a; is >> a; rhs = a; return is;}
};

//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;

using mint = ModInt<MOD>;

void practice2_k() {
    using P = pair<mint, mint>;
    int N,Q; cin >> N >> Q;
    vector<P> A(N);
    rep(i,N) {
        int a; cin >> a;
        A[i] = P(a,1);
    }

    auto f=[](P a, P b) {return P(a.first+b.first, a.second+b.second);};
    auto g=[](P a, P val) {
        return P(a.first*val.first+a.second*val.second, a.second);
    };
    auto h=[](P a, P b) {return P(a.first*b.first, a.second*b.first+b.second);};
    const P e = P(0,0);
    const P id = P(1,0);
    LazySegmentTree seg(f,g,h,e,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            cout << seg.get(l,r).first << ln;
        } else {
            int l,r,b,c; cin >> l >> r >> b >> c;
            seg.apply(l,r,P(b,c));
        }
    }
}

struct Node {
    ll cnt0, cnt1, cnt01, cnt10;
    Node () {}
    Node (ll cnt0, ll cnt1, ll cnt01, ll cnt10) : cnt0(cnt0), cnt1(cnt1), cnt01(cnt01), cnt10(cnt10) {}
};

void practice2_l() {
    int N,Q; cin >> N >> Q;
    vector<Node> A(N);
    rep(i,N) {
        int a; cin >> a;
        A[i].cnt0 = 1-a;
        A[i].cnt1 = a;
    }
 
    auto f=[](Node a, Node b) {
        return Node(a.cnt0+b.cnt0,a.cnt1+b.cnt1,a.cnt01+b.cnt01+a.cnt0*b.cnt1,a.cnt10+b.cnt10+a.cnt1*b.cnt0);
    };
    auto g=[](Node a, int val) {
        if (val) return Node(a.cnt1,a.cnt0,a.cnt10,a.cnt01);
        return a;
    };
    auto h=[](int a, int b) {return a^b;};
    const Node e = Node(0,0,0,0);
    const int id = 0;
    LazySegmentTree seg(f,g,h,e,id,A);
 
    while (Q--) {
        int t,l,r; cin >> t >> l >> r;
        --l;
        if (t==1) seg.apply(l,r,1);
        else {
            cout << seg.get(l,r).cnt10 << ln;
        }
    }
}

void DSL_2_F() {
    int N,Q; cin >> N >> Q;
    vector<ll> A(N,(1LL<<31)-1);
    auto f=[](ll a, ll b) {return min(a,b);};
    auto g=[](ll a, ll val) {return val;};
    auto h=[](ll a, ll b) {return b;};
    const ll e = 1e18;
    const ll id = -1;
    LazySegmentTree seg(f,g,h,e,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            r++;
            cout << seg.get(l,r) << ln;
        } else {
            ll l,r,x; cin >> l >> r >> x;
            r++;
            seg.apply(l,r,x);
        }
    }
}

void DSL_2_G() {
    int N,Q; cin >> N >> Q;
    auto f=[](pll a, pll b) {return pll(a.first+b.first,a.second+b.second);};
    auto g=[](pll a, ll val) {return pll(a.first+val*a.second,a.second);};
    auto h=[](ll a, ll b) {return a+b;};
    const pll e = pll(0,0);
    const ll id = 0;
    vector<pll> A(N,pll(0,1));
    LazySegmentTree seg(f,g,h,e,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            l--;
            cout << seg.get(l,r).first << ln;
        } else {
            int l,r,x; cin >> l >> r >> x;
            l--;
            seg.apply(l,r,x);
        }
    }
}

void DSL_2_H() {
    int N,Q; cin >> N >> Q;
    auto f=[](ll a, ll b) {return min(a,b);};
    auto g=[](ll a, ll val) {return a+val;};
    auto h=[](ll a, ll b) {return a+b;};
    const ll e = 1e18;
    const ll id = 0;
    vector<ll> A(N);
    LazySegmentTree seg(f,g,h,e,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            r++;
            cout << seg.get(l,r) << ln;
        } else {
            ll l,r,x; cin >> l >> r >> x;
            r++;
            seg.apply(l,r,x);
        }
    }
}

void DSL_2_I() {
    int N,Q; cin >> N >> Q;
    auto f=[](pll a, pll b) {return pll(a.first+b.first,a.second+b.second);};
    auto g=[](pll a, ll val) {return pll(val*a.second,a.second);};
    auto h=[](ll a, ll b) {return b;};
    const pll e = pll(0,0);
    const ll id = 1e18;
    vector<pll> A(N,pll(0,1));
    LazySegmentTree seg(f,g,h,e,id,A);

    while (Q--) {
        int t; cin >> t;
        if (t) {
            int l,r; cin >> l >> r;
            r++;
            cout << seg.get(l,r).first << ln;
        } else {
            int l,r,x; cin >> l >> r >> x;
            r++;
            seg.apply(l,r,x);
        }
    }
}

void practice2_j() {
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
 
    auto f=[](int a, int b) {return max(a,b);};
    auto g=[](int a, int val) {return val;};
    auto h=[](int a, int b) {return b;};
    const int e = -1;
    const int id = -1;
    LazySegmentTree seg(f,g,h,e,id,A);
 
    while (Q--) {
        int t; cin >> t;
        if (t==1) {
            int x,v; cin >> x >> v;
            x--;
            seg.apply(x,v);
            //seg.set(x,v);
        } else if (t==2) {
            int l,r; cin >> l >> r;
            l--;
            cout << seg.get(l,r) << ln;
        } else {
            int x,v; cin >> x >> v;
            x--;
            auto check=[&](int val) {return v > val;};
            cout << seg.max_right(x,check)+1 << ln;
        }
    }
}

int main() {
    //practice2_k();
    //practice2_l();
    //DSL_2_F();
    //DSL_2_G();
    //DSL_2_H();
    //DSL_2_I();
    practice2_j();
}

/*
  verified on 2020/09/20
  https://atcoder.jp/contests/practice2/tasks/practice2_k
  https://atcoder.jp/contests/practice2/tasks/practice2_l
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=ja
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&lang=ja
  https://atcoder.jp/contests/practice2/tasks/practice2_j
*/