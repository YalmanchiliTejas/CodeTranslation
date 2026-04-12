#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug_print.hpp"
#else
void debug(...) {}
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, X, M;
    cin >> N >> X >> M;

    ll ans = 0;
    ll x = X;
    ll cnt = 0;
    map<ll, ll> mp;
    for(ll i = 0; i<N; i++) {
        if(mp[x]) {
            ll loop = cnt - mp[x] + 1;
            debug(ans, i, loop, mp[x]);
            ll p = 0;
            for(int j=mp[x]-1; j<i; j++) {
                p += x;
                x *= x;
                x %= M;
            }
            ans += ((N - mp[x] + 1) / loop - 1) * p;
            i = N - (N - mp[x] + 1) % loop;
            mp.clear();
            debug(ans, i, p);
            if(i >= N) break;
        }
        else {
            mp[x] = i + 1;
            cnt++;
        }
        ans += x;
        x *= x;
        x %= M;
        debug("x=", x);
    }
    cout << ans << endl;

    return 0;
}
