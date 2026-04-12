#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define int ll

void solve();
ll calc(int);


const int MAXC = 100005;

ll n, x, m, pos[MAXC], in[MAXC];
vector<ll> s;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> x >> m)
        solve();
    return 0;
}

void solve() {
    memset(pos, 0, sizeof(pos));

    ll sum = x;
    in[1] = x;
    pos[x] = 1;

    for (ll i = 2; i <= n; ++i) {
        x = (x * x) % m;

        if (pos[x]) {
            s.clear();
            for (ll l = pos[x]; l < i; ++l) s.push_back(in[l]);

            sum += calc(n - i + 1);
            cout << sum  << '\n';
            return;
        } else {
            in[i] = x;
            pos[x] = i;
            sum += x;
        }
    }
    cout << sum << '\n';
}

ll calc(ll len) {
    ll ans = 0, sum = 0;
    ll sz = s.size();

    for (ll i = 0; i < sz; ++i) sum += s[i];
    ans = sum * (len / sz);
    len %= sz;

    for (ll i = 0; i < len; ++i) ans += s[i];

    return ans;
}
