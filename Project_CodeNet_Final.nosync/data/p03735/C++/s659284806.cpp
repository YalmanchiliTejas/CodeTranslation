#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const int INF = TEN(9) + 10;

int main() {
    int N;
    cin >> N;
    V<pii> pt(N);
    ll rmin = INF, rmax = -1, bmin = INF, bmax = -1;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        pt[i] = mp(x, y);
        chmin(rmin, x);
        chmax(rmax, x);
        chmin(bmin, y);
        chmax(bmax, y);
    }

    ll amax = max(rmax, bmax);
    ll amin = min(rmin, bmin);

    ll ans = (rmax - rmin) * (bmax - bmin);

    sort(ALL(pt));
    multiset<int> st;
    rep(i, N) st.insert(pt[i].fi);
    rep(i, N) {
        int x, y;
        tie(x, y) = pt[i];
        st.erase(st.find(x));
        st.insert(y);
        chmin(ans, (amax - amin) * (*st.rbegin() - *st.begin()));
    }

    cout << ans << endl;

    return 0;
}