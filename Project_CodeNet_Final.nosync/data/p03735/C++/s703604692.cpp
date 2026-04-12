#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<PII> p(n);
    REP(i, n) {
        ll u, v;
        cin >> u >> v;
        p[i] = minmax(u, v);
    }
    
    sort(ALL(p));
    ll mi = INF, ma = -INF;
    ll idx1 = -1, idx2 = -1;
    vector<ll> x(n), y(n);
    REP(i, n) {
        x[i] = p[i].first, y[i] = p[i].second;
        if(mi > x[i]) mi = x[i], idx1 = i;
        if(ma < y[i]) ma = y[i], idx2 = i;
    }
    dump(x, y);

    ll rmin = INF, rmax = -INF, bmin = INF, bmax = -INF;
    REP(i, n) {
        chmin(rmin, x[i]);
        chmax(rmax, x[i]);
        chmin(bmin, y[i]);
        chmax(bmax, y[i]);
    }
    ll ret = (rmax - rmin) * (bmax - bmin);
    dump(ret);

    multiset<ll> st;
    st.insert(y[idx1]);
    st.insert(x[idx2]);
    REP(i, n) {
        if(i == idx1 || i == idx2) continue;
        st.insert(x[i]);   
    }
    dump(st);
    chmin(ret, (ma-mi) * (*st.rbegin() - *st.begin()));
    REP(i, n) {
        if(i == idx1 || i == idx2) continue;
        st.erase(st.find(x[i]));
        st.insert(y[i]);
        dump(st);
        chmin(ret, (ma-mi) * (*st.rbegin() - *st.begin()));
    }

    cout << ret << endl;

    return 0;
}