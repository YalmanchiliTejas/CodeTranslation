#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for (int i = (int)(n); i > 0; --i)
#define loop(i,x,n) for (int i = (int)(x); i < (n); ++i)
#define loops(i,x,n) for (int i = (int)(x); i <= (n); ++i)
#define loopd(i,x,n) for (int i = (int)(x); i > (n); --i)
#define loopds(i,x,n) for (int i = (int)(x); i >= (n); --i)
#define itrep(i,a) for (auto i = begin(a); i != end(a); ++i)
#define itrepd(i,a) for (auto i = rbegin(a); i != rend(a); ++i)
#define all(f,x,...) [&](decltype(x)& whole) { return (f)(begin(whole), end(whole), ##__VA_ARGS__); }(x)
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e18);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e18;
ll mod = static_cast<ll>(1e9 + 7);
template<class T> constexpr int sz(const T& a) { return (int)a.size(); }
template<class T> constexpr T pow2(const T a) { return a * a; }
template<class T, class ... Args> constexpr void mins(T& a, Args... args) { a = min<T>({ a, args... }); }
template<class T, class... Args> constexpr void maxs(T& a, Args... args) { a = max<T>({ a,args... }); }
template<class A, int N, class T>
void fillArray(A(&array)[N], const T& val) { std::fill((T*)array, (T*)(array + N), val); }

// 区間 min or max
template<class T>
class SegmentTree2 {
public:
    SegmentTree2(int n_, T init, T limit_, std::function<T(T, T)> comp_) :n(1), limit(limit_), comp(comp_) {
        while (n < n_) n *= 2;
        d.resize(2 * n - 1, init); v.resize(2 * n - 1, 0);
    };
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return limit;
        if (a <= l && r <= b) return d[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) >> 1);
        T vr = query(a, b, k * 2 + 2, (l + r) >> 1, r);
        return v[k] + comp(vl, vr);
    }
    void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (l >= r) return;
        if (a <= l && r <= b) {
            v[k] += x; d[k] += x;
        }
        else if (a < r && l < b) {
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
            d[k] = v[k] + comp(d[k * 2 + 1], d[k * 2 + 2]);
        }
    }
private:
    const T limit;
    std::function<T(T, T)> comp;
    int n;
    vector<T> v, d;
};


int n, m;
vector<ll> add[200005];
vector<pair<int, ll>> del[200005];
void solve() {
    cin >> n >> m;
    rep(i, m) {
        int l, r, x;
        cin >> l >> r >> x;
        add[l].push_back(x);
        del[r].emplace_back(l, x);
    }

    ll ma = 0;
    SegmentTree2<ll> st(n, 0, -inf, [](ll a, ll b) { return max(a, b); });
    reps(i, n) {
        for (auto& a : add[i]) st.add(0, i, a);
        ll v = st.query(0, i);
        ma = max(ma, v);
        st.add(i, i + 1, v);
        for (auto& a : del[i]) st.add(0, a.first, -a.second);
    }
    cout << ma << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
