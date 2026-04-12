#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }} template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
    using P = function< OperatorMonoid(OperatorMonoid, int) >;
    
    int sz;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const P p;
    const Monoid M1;
    const OperatorMonoid OM0;
    
    
    LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                    const Monoid &M1, const OperatorMonoid OM0)
    : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
    {
        sz = 1;
        while(sz < n) sz <<= 1;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }
    
    void set(int k, const Monoid &x)
    {
        data[k + sz] = x;
    }
    
    void build()
    {
        for(int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }
    
    void propagate(int k, int len)
    {
        if(lazy[k] != OM0) {
            if(k < sz) {
                lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            }
            data[k] = g(data[k], p(lazy[k], len));
            lazy[k] = OM0;
        }
    }
    
    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
    {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return data[k];
        } else if(a <= l && r <= b) {
            lazy[k] = h(lazy[k], x);
            propagate(k, r - l);
            return data[k];
        } else {
            return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                               update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    
    Monoid update(int a, int b, const OperatorMonoid &x)
    {
        return update(a, b, x, 1, 0, sz);
    }
    
    
    Monoid query(int a, int b, int k, int l, int r)
    {
        propagate(k, r - l);
        if(r <= a || b <= l) {
            return M1;
        } else if(a <= l && r <= b) {
            return data[k];
        } else {
            return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
                     query(a, b, 2 * k + 1, (l + r) >> 1, r));
        }
    }
    
    Monoid query(int a, int b)
    {
        return query(a, b, 1, 0, sz);
    }
    
    Monoid operator[](const int &k)
    {
        return query(k, k + 1);
    }
};

const lint MIN = -1e18;

int main(){
    int N, M;
    cin >> N >> M;
    auto f = [](lint a, lint b) { return max(a, b); };
    auto g = [](lint a, lint b) { return a + b; };
    auto h = [](lint a, lint b) { return a + b; };
    auto p = [](lint a, lint b) { return a; };
    LazySegmentTree<lint> seg(N + 2, f, g, h, p, MIN, 0);
    vector<pair<int, lint>> sections_left[N + 1];
    for(int i = 0; i < M; i++){
        int l, r;
        lint a;
        cin >> l >> r >> a;
        l--;
        sections_left[l].push_back({r, a});
    }
    seg.update(N + 1, N + 2, -MIN);
    for(int l = N; l >= 0; l--){
        for(auto i: sections_left[l]){
            int r = i.first;
            lint a = i.second;
            seg.update(l + 1, r + 1, a);
        }
        lint ans = seg.query(l + 1, N + 2);
        seg.update(l, l + 1, ans - MIN);
    }
    cout << seg[0] << endl;
}
