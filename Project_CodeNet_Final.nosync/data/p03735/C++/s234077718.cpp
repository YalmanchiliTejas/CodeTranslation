// Crt. 2019-12-10  21:36:00

#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int n;
ll pmx[N], pmi[N], smx[N];
struct Node { ll x, y; } p[N];

inline bool cmp(Node a, Node b) {
    return a.x > b.x;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    ll tmp = 2e18;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        if (p[i].x < p[i].y) swap(p[i].x, p[i].y);
        tmp = min(tmp, p[i].y);
    }

    for (int i = 1; i <= n; ++i)
        if (p[i].y == tmp) { swap(p[i], p[n]); break;}

    sort(p + 1, p + n, cmp);

    ll ans = 2e18;
    
    pmx[1] = pmi[1] = p[1].y;
    for (int i = 2; i <= n; ++i)
        pmx[i] = max(pmx[i - 1], p[i].y),
        pmi[i] = min(pmi[i - 1], p[i].y);

    smx[n] = p[n].y;
    for (int i = n - 1; i >= 1; --i)
        smx[i] = max(smx[i + 1], p[i].y);

//    for (int i = 1; i <= n; ++i)
//        cout << p[i].x << " " << p[i].y << endl;

    for (int i = 1; i < n; ++i) {
        ll Rmax = p[1].x, Rmin = p[n].y;
        ll Bmax = max(p[n].x, max(pmx[i], p[i + 1].x));
        ll Bmin = min(p[n].x, min(pmi[i], i != n - 1 ? p[n - 1].x : INF));
        //cout  << i << " " << Rmax << " " << Rmin << " " << Bmax << " " << Bmin << endl;
        ans = min(ans, (Rmax - Rmin) * (Bmax - Bmin));
    }

    for (int i = 1; i < n; ++i) {
        ll Rmax = max((i != n - 1 ? p[i + 1].x : p[i + 1].y), max(pmx[i], i + 2 < n ? smx[i + 2] : 0));
        ll Rmin = p[n].y, Bmax = max(p[1].x, p[n].x);
        ll Bmin = min(p[n].x, min(i != n - 2 ? p[n - 1].x : p[i].x, i != n - 1 ? p[i + 1].y : INF));
        //cout  << i << " " << Rmax << " " << Rmin << " " << Bmax << " " << Bmin << endl;
        ans = min(ans, (Rmax - Rmin) * (Bmax - Bmin));
    }

    cout << ans << endl;

    return 0;
}
