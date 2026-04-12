#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
template<class V, int NV> struct LazySegTree { // [L,R)
    vector<V> dat, lazy; LazySegTree() { dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); }
    void update(int a, int b, V v, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return;
        if (a <= l && r <= b) { setLazy(k, v); push(k, l, r); } else {
        update(a, b, v, k * 2 + 1, l, (l + r) / 2); update(a, b, v, k * 2 + 2, (l + r) / 2, r);
        dat[k] = comp(dat[k * 2 + 1], dat[k * 2 + 2]);}}
    V get(int a, int b, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return dat[k]; auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 2, (l + r) / 2, r); return comp(x, y);}
    void update(int a, int b, V v) { update(a, b, v, 0, 0, NV); }
    V get(int a, int b) { return get(a, b, 0, 0, NV); }
    // ---- Template ---------------------------------------------------------------------------------
    
    // 区間add, 区間max
    const V def = 0, ldef = 0;
    V comp(V l, V r) { return max(l, r); }
    void setLazy(int i, V v) { lazy[i] += v; }
    void push(int k, int l, int r) {
        dat[k] += lazy[k];
        if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
        lazy[k] = ldef;
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/











int N, M;
LazySegTree<ll, 1 << 18> dp;
vector<pair<int, int>> R[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        int l, r, a; cin >> l >> r >> a;
        l--; r--;
        R[r].push_back({ l,a });
    }

    rep(r, 0, N) {
        ll opt = dp.get(0, r);
        dp.update(r, r + 1, opt);
        fore(p, R[r]) {
            int l, a; tie(l, a) = p;
            dp.update(l, r + 1, a);
        }
    }

    ll ans = dp.get(0, N);
    cout << ans << endl;
}
