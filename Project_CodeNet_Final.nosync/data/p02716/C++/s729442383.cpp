#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], pref[maxn], L[maxn], R[maxn];
map < pair < int, int >, int > f;
int inf = 1e18;
set < pair < int, pair < int, int > > > Q;

int get(int l, int r) {
    return pref[r] - pref[max(0ll, l - 2)] - (pref[r - 1] - pref[max(0ll, l - 1)]);
}

void del(int l, int r) {
    Q.erase({f[{l, r}], {l, r}});
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    a[1] = -inf;
    for (int i = 2; i <= n + 1; ++i) cin >> a[i];
    a[n + 2] = -inf;
    for (int i = 1; i <= n + 2; ++i) pref[i] = pref[max(i - 2, 0ll)] + a[i];
    for (int i = 1; i <= n + 2; ++i) Q.insert({a[i], {i, i}}), L[i] = i, R[i] = i, f[{i, i}] = a[i];
    for (int i = 1; i <= n / 2; ++i) {
        auto p = (*Q.rbegin());
        ans += p.first;
        Q.erase(p);
        int l = p.second.first, r = p.second.second;
        int nxtl = R[l - 1], nxtr = L[r + 1];
        del(nxtl, l - 1);
        del(r + 1, nxtr);
        Q.insert({get(nxtl, nxtr), {nxtl, nxtr}});
        L[nxtl] = nxtr, R[nxtr] = nxtl;
        f[{nxtl, nxtr}] = get(nxtl, nxtr);
    }
    cout << ans << '\n';
    return 0;
}

