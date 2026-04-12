#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Segment Tree
template<class Monoid, class Action> struct SegTree {
    using FuncMonoid = function< Monoid(Monoid, Monoid) >;
    using FuncAction = function< void(Monoid&, Action) >;
    using FuncLazy = function< void(Action&, Action) >;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;

    SegTree() { }
    SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
    : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy) {
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy) {
        FM = fm; FA = fa; FL = fl;
        UNITY_MONOID = unity_monoid; UNITY_LAZY = unity_lazy;
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k*2], dat[k*2+1]);
    }

    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == UNITY_LAZY) return;
        if (k < SIZE) FL(lazy[k*2], lazy[k]), FL(lazy[k*2+1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)  FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1), update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = FM(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }

    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k*2, l, (l+r)>>1), get(a, b, k*2+1, (l+r)>>1, r));
        else
            return UNITY_MONOID;
    }
    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator [] (int a) { return get(a, a+1); }
    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) { cout << (*this)[i]; if (i != SIZE) cout << ","; }
        cout << endl;
    }
};

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    ll m;
    cin>>m;
    ll a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    ll n = m/2;
    ll INF = 1e10;
    auto fm = [](long long a, long long b) { return max(a,b);};
    auto fm2 = [](ll a,ll b){ return min(a,b);};
    auto fa = [](long long &a, long long d) { a = a + d; };
    auto fl = [](long long &d, long long e) { d = d + e; };
    SegTree<long long, long long> seg(n+1, fm, fa, fl, 0, 0);
    SegTree<ll,ll> seg2(n+1,fm2,fa,fl,0,0);

    for(int i=0;i<n;i++){
        seg.update(i,i+1,a[i]-a[m-1-i]);
        seg2.update(i,i+1,a[i]-a[m-1-i]);
    }
    int q;
    cin>>q;
    while(q--){
        ll a,b,x;
        cin>>a>>b>>x;
        a--,b--;
        seg.update(min(a,n),min(b+1,n),x);
        seg2.update(min(a,n),min(b+1,n),x);
        seg.update(min(m-1-b,n),min(m-a,n),-x);
        seg2.update(min(m-1-b,n),min(n,m-a),-x);

        // cerr << "d1 "<<min(a,n) << " " << min(b+1,n) <<endl;
        // cerr << "d2 "<<min(n,m-b) << " " << min(m-a,n) << endl;
        // cerr<< seg.get(0,n) << " " << seg2.get(0,n) << " ";
        if(seg.get(0,n) == 0 && seg2.get(0,n)==0){
            cout << 1 << "\n";
        }
        else cout <<0 << "\n";
    }
}
