#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, N) for (int i = 0; i < (N); ++i)
#define fi first
#define se second

template<typename T, typename S>
bool chmax(T &a, const S &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T, typename S>
bool chmin(T &a, const S &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1LL << 60;
int N;
vector<pair<int, int>> V;

signed main() {
    cin >> N;
    V.resize(N);
    REP(i, N) cin >> V[i].fi >> V[i].se;
    REP(i, N) if (V[i].fi > V[i].se) swap(V[i].fi, V[i].se);
    sort(V.begin(), V.end());

    ll res = INF;
    ll mx = -INF, mn = INF;

    for (auto& [x, y]: V) {
        chmax(mx, y);
        chmin(mn, x);
    }

    {
        pair<ll, ll> red(-INF, INF), blue(-INF, INF);
        for (auto& [x, y]: V) {
            // fi -> red
            chmax(red.fi, x);
            chmin(red.se, x);
            // se -> blue
            chmax(blue.fi, y);
            chmin(blue.se, y);
        }
        chmin(res, (red.fi - red.se) * (blue.fi - blue.se));
        //cerr << res << " : " << red.fi << ' ' << red.se << ' ' << blue.fi << ' ' << blue.se << endl;
    }

    {
        multiset<int> st;
        REP(i, N) st.emplace(V[i].fi);
        chmin(res, (mx - mn) * (*st.rbegin() - *st.begin()));
        for (auto& [x, y]: V) {
            st.erase(st.find(x));
            st.emplace(y);
            chmin(res, (mx - mn) * (*st.rbegin() - *st.begin()));
            //cerr << res << endl;
        }
    }

    cout << res << endl;
}
