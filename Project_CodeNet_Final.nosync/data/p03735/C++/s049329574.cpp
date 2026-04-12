#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;

#define MAX 200001
priority_queue<PLL> pq;

int main(void) {
    int i, n;
    ll x, y;
    ll Rmax = -1, Rmin = 2e9, Bmax = -1, Bmin = 2e9;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%lld%lld", &x, &y);
        if(x > y) swap(x, y);
        pq.push(make_pair(y, x));
        Rmax = max(Rmax, x);
        Bmax = max(Bmax, y);
        Rmin = min(Rmin, x);
        Bmin = min(Bmin, y);
    }
    ll ans = (Rmax - Rmin) * (Bmax - Bmin);
    while(!pq.empty()) {
        PLL u = pq.top(); pq.pop();
        if(u.second >= u.first) break;
        Rmax = max(Rmax, u.first);
        Bmin = min(Bmin, u.second);
        swap(u.first, u.second);
        pq.push(u);
        ans = min(ans, 1LL * (Rmax - Rmin) * (pq.top().first - Bmin));
    }
    printf("%lld\n", ans);
    return 0 ;
}