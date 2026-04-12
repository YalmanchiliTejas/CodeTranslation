#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1'000'000'007;

ll p2(ll e) {
    if (e == 0) return 1;
    if (e == 1) return 2;
    if (e & 1) return 2 * p2(e - 1) % mod;
    ll r = p2(e >> 1);
    return r * r % mod;
}

ll solve(vector<ll>& hs) {
    if (hs.empty()) return 1;
    set<ll> vset(hs.begin(), hs.end());
    vector<ll> vs(vset.begin(), vset.end());
    map<ll,int> vi;
    for (int i = 0; i < vs.size(); i++) vi[vs[i]] = i;
    vector<ll> ans(vs.size(), 1LL);
    ll total = 1;
    ll ph = 0;
    for (ll h: hs) {
        if (ph == 0) {
            for (int i = 0; i <= vi[h]; i++) {
                ans[i] = p2(h - vs[i]);
            }
            total = p2(h);
        } else if (ph <= h) {
            vector<ll> pans(ans.begin(), ans.end());
            for (int i = 0; i <= vi[h]; i++) {
                ans[i] = (pans[min(i, vi[ph])] + pans[vi[ph]]) * p2(h - max(vs[i], ph));
                ans[i] %= mod;
            }
            total = (total + 2 * pans[vi[ph]]) * p2(h - ph);
            total %= mod;
        } else {
            vector<ll> pans(ans.begin(), ans.end());
            for (int i = 0; i <= vi[h]; i++) {
                ans[i] = pans[i] + pans[vi[h]];
                ans[i] %= mod;
            }
            total = (total + 2 * pans[vi[h]]);
            total %= mod;
        }
        ph = h;
        // printf("after h = %lld: total = %lld\n", h, total);
        // for (int i = 0; i < vs.size(); i++) {
        //     printf("%lld: %lld\n", vs[i], ans[i]);
        // }
        // printf("\n");
    }
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> h;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ll v;
        scanf("%lld", &v);
        if (v == 1) {
            ans *= 2;
            ans %= mod;
            ans *= solve(h);
            ans %= mod;
            h.clear();
        } else {
            h.push_back(v);
        }
    }
    ans *= solve(h);
    ans %= mod;
    printf("%lld\n", (ans % mod + mod) % mod);
}