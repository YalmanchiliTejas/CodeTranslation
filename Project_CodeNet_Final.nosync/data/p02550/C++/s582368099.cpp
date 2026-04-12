#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n, x, m;
    cin >> n >> x >> m;

    vector<vector<ll>> nxt(40, vector<ll>(m, 0));
    vector<vector<ll>> s(40, vector<ll>(m, 0));
    REP(y, m){
        nxt.at(0).at(y) = (y * y) % m;
        s.at(0).at(y) = y;
    }

    for(ll i = 1; i < 40; ++i){
        REP(y, m){
            const ll n1 = nxt.at(i - 1).at(y);
            s.at(i).at(y) = s.at(i - 1).at(n1) + s.at(i - 1).at(y);
            nxt.at(i).at(y) = nxt.at(i - 1).at(n1);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < 40; ++i){
        if((n >> i) & 1){
            ans += s.at(i).at(x);
            x = nxt.at(i).at(x);
        }
    }
    cout << ans << endl;
    return 0;
}
