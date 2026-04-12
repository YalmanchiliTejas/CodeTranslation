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

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

// [min, _], [_, max]
ll calc1(V<ll> x, V<ll> y, const int &n) {
    ll xmn = inf, xmx = -inf, ymn = inf, ymx = -inf;
    rep(i, n) {
        if(x[i] > y[i]) swap(x[i], y[i]);
        chmin(xmn, x[i]);
        chmax(xmx, x[i]);
        chmin(ymn, y[i]);
        chmax(ymx, y[i]);
    }
    return (xmx - xmn) * (ymx - ymn);
}

// [min, max], [_, _]
ll calc2(V<ll> x, V<ll> y, const int &n) {
    V<int> p(n);
    multiset<ll> st;
    ll mn = inf, mx = -inf;
    rep(i, n) {
        p[i] = i;
        if(x[i] > y[i]) swap(x[i], y[i]);
        chmin(mn, x[i]);
        chmax(mx, y[i]);
        st.insert(x[i]);
    }
    sort(ALL(p), [&](int a, int b) { return x[a] < x[b]; });
    ll res = (mx - mn) * (*st.rbegin() - *st.begin());
    for(int i : p) {
        st.erase(st.find(x[i]));
        st.insert(y[i]);
        chmin(res, (mx - mn) * (*st.rbegin() - *st.begin()));
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    V<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << min(calc1(x, y, n), calc2(x, y, n)) << endl;

    return 0;
}