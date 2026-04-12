#line 2 "header.hpp"

//%snippet.set('header')%
//%snippet.fold()%
#ifndef HEADER_H
#define HEADER_H

// template version 2.0
using namespace std;
#include <bits/stdc++.h>

// varibable settings
const long long INF = 1e18;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a) = (b); }
template <class T, class U> inline void chmin(T &a, const U &b) { if ((a) > (b)) (a) = (b); }
template <typename X, typename T> auto make_table(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y, z, zs...); return vector<decltype(cont)>(x, cont); }

#define cdiv(a, b) (((a) + (b)-1) / (b))
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef long double ld;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
void check_input() { assert(cin.eof() == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif

#endif /* HEADER_H */
//%snippet.end()%
#line 2 "solve.cpp"
template<class T=ll> using vec = vector<T>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

// snippet:segment_tree {{{
template <typename T> struct SegmentTree {  // {{{
    private:
        using F = function<T(T, T)>;
        int n;  // 元の配列のサイズ
        int N;  // n以上の最小の2冪
        vector<T> node;
        F merge;
        T identity;

    public:
        SegmentTree() {}
        SegmentTree(vector<T> a, F f, T id) : merge(f), identity(id) {
            n = a.size();
            N = 1;
            while (N < n) N *= 2;
            node.resize(2 * N - 1, identity);
            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];
            for (int i = N - 2; i >= 0; i--)
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
        }
        SegmentTree(int n, F f, T id) : SegmentTree(vector<T>(n, id), f, id) {}

        T& operator[](int i) { return node[i + N - 1]; }

        void update(int i, T val) {
            i += (N - 1);
            node[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        void add(int i, T val) {
            i += (N - 1);
            node[i] += val;
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
            }
        }

        // query for [a, b)
        T query(int a, int b, int k = 0, int l = 0, int r = -1) {
            if (r < 0) r = N;
            if (r <= a || b <= l) return identity;
            if (a <= l && r <= b) return node[k];

            T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return merge(vl, vr);
        }

        // find most right element for [a, b)
        int find_mr(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r = -1){
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return a-1;
            if (k >= N-1) return k - (N-1);  // leaf

            T vr = find_mr(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            if (vr != a-1) return vr;

            T vl = find_mr(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            return vl;
        }

        // find most left element for [a, b)
        int find_ml(int a, int b, function<bool(T)> is_ok, int k = 0, int l = 0, int r = -1){
            // find most left
            if (r < 0) r = N;
            if (r <= a || b <= l || !is_ok(node[k])) return b;
            if (k >= N-1) return k - (N-1);  // leaf

            T vl = find_ml(a, b, is_ok, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) return vl;

            T vr = find_ml(a, b, is_ok, 2 * k + 2, (l + r) / 2, r);
            return vr;
        }

#if defined(PCM) || defined(LOCAL)
        friend ostream& operator<<(ostream& os, SegmentTree<T>& sg) {  //
            os << "[";
            for (int i = 0; i < sg.n; i++) {
                os << sg[i] << (i == sg.n - 1 ? "]\n" : ", ");
            }
            return os;
        }
#endif
};/*}}}*/

int solve() {
    ll n,q;cin>>n>>q;
    vector<ll> a(n);
    rep(i, n) {
        cin>>a[i];
    }
    auto mymax=[](auto a, auto b){return max(a,b);};
    SegmentTree<ll> seg(a, mymax, -1e18);
    rep(_, q){
        ll t;cin>>t;
        if (t == 1){
            ll i,v;cin>>i>>v;
            i--;
            seg.update(i, v);
        }
        else if (t == 2){
            ll l,r;cin>>l>>r;
            l--;r--;
            cout << seg.query(l, r+1) << endl;
        }
        else if (t == 3){
            ll i,v;cin>>i>>v;
            i--;
            auto isok = [&](auto x){
                return x >= v;
            };
            cout << seg.find_ml(i, n, isok) + 1 << endl;
        }
    }

    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/


