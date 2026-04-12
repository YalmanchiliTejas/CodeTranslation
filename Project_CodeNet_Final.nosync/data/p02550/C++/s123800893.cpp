#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 998244353;
const ll N = 720006;
const ll INF = 1e18;
vector<ll> p(N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, x;
    cin >> n >> x >> m;
    for(ll i = 0; i < m; i++) {
        p[i] = (i * i) % m;
    }

    ll st = x % m;
    ll ans = 0;
    ll cur = 0;
    vector<bool>seen(m + 1, false);
    seen[st] = true;
    ans += st;
    cur++;
    st = p[st];
    
    while(cur < n && !seen[st]) {
        ans += st;
        cur++;
        seen[st] = true;
        st = p[st];
    }
    if(cur == n) {
        cout << ans << '\n';
        return 0;
    }

    vector<ll> cyc;
    ll nd = st;
    while(p[st] != nd) {
        cyc.pb(st);
        st = p[st];
    }
    cyc.pb(st);
    for(int i = 1; i < cyc.size(); i++) {
        cyc[i] += cyc[i - 1];
    }


    n -= cur;
    ans += cyc.back() * (n / (ll) cyc.size());
    if(n % (ll) cyc.size()) {
        ans += cyc[(n % (ll) cyc.size()) - 1];
    }
    cout << ans << '\n';

    return 0;
}