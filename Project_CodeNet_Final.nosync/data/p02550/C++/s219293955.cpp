#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < ll(n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;
// cout << fixed << setprecision(10）<<  << endl;

int main() {
    ll n, x, m; cin >> n >> x >> m;
    vector<ll> sub(m,0ll);
    ll save = x;

    map<ll,ll> check;

    rep(i,n){
        if (save == 0) {
            ll ans = 0ll;
            rep(j,m) ans += sub[j];
            cout << ans << endl;
            return 0;
        }
        sub[i] = save;
        check[save]++;
        save = save * save % m;
        if (check[save] > 0ll) {
            ll id = -1;
            rep(j,m) if(sub[j] == save) { id = j; break; }
            ll ans = 0;
            rep(j,id) ans += sub[j];
            ll roop = 0;
            for (ll j = id; j <= i; j++) roop += sub[j];
            n -= id;
            ans += roop * (n / (i + 1 - id));
            n %= (i + 1 - id);
            rep(j,n) ans += sub[id+j];
            cout << ans << endl;
            return 0;
        }
    }
    ll ans = 0;
    rep(i,n) ans += sub[i];
    cout << ans << endl;
    return 0;
}