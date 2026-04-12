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
    vector<vector<ll>> g(n);
    REP(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    stack<ll> st;
    vector<ll> deg(n);
    vector<bool> del(n);
    REP(i, n) {
        deg[i] = g[i].size();
        if(deg[i] == 1) st.push(i);
    }
    while(st.size()) {
        ll v = st.top(); st.pop();
        if(del[v]) continue;
        // v と g[v] のうち残ってるやつ を消す
        bool first = true;
        dump(v);
        del[v] = true;
        for(auto i: g[v]) if(!del[i]) {
            if(first) {
                dump(i);
                del[i] = true;
                for(auto j: g[i]) if(!del[j]) {
                    deg[j]--;
                    if(deg[j] == 1) st.push(j);
                }
                first = false;
            }
            deg[i]--;
        }
        if(first) {
            cout << "First" << endl;
            return 0;
        }
    }

    cout << "Second" << endl;

    return 0;
}