#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

ll calc1(int n, V<ll> x, V<ll> y) {
    rep(i, n) if(x[i] > y[i]) swap(x[i], y[i]);
    sort(ALL(x));
    sort(ALL(y));
    return (x.back() - x.front()) * (y.back() - y.front());
}

ll calc2(int n, V<ll> x, V<ll> y) {
    using P = array<ll, 2>;
    V<P> v;
    ll mn = inf, mx = -inf;
    multiset<ll> st;
    rep(i, n) {
        if(x[i] > y[i]) swap(x[i], y[i]);
        v.push_back(P{x[i], y[i]});
        chmin(mn, x[i]);
        chmax(mx, y[i]);
        st.insert(x[i]);
    }
    sort(ALL(v));
    ll ret = (mx - mn) * (*st.rbegin() - *st.begin());
    rep(i, n) {
        st.erase(st.find(v[i][0]));
        st.insert(v[i][1]);
        chmin(ret, (mx - mn) * (*st.rbegin() - *st.begin()));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    V<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << min(calc1(n, x, y), calc2(n, x, y)) << endl;

    return 0;
}