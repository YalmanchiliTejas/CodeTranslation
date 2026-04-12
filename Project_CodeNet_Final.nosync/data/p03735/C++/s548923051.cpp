#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int x[200005], y[200005];
pii p[200005];
int main(){
    int n;
    scanf("%d", &n);

    int mx = 0, mn = 1e9;
    for(int i=1;i<=n;i++){
        scanf("%d%d", &x[i], &y[i]);
        mx = max(mx, x[i]);
        mx = max(mx, y[i]);
        mn = min(mn, x[i]);
        mn = min(mn, y[i]);
    }

    int r1 = 0, r2 = 1e9, b1 = 0, b2 = 1e9;
    for(int i=1;i<=n;i++){
        if(x[i] < y[i]) swap(x[i], y[i]);
        r1 = max(r1, x[i]);
        r2 = min(r2, x[i]);

        b1 = max(b1, y[i]);
        b2 = min(b2, y[i]);
    }
    ll ans = (r1-r2)*1ll*(b1-b2);

    for(int i=1;i<=n;i++) p[i] = pii(y[i], x[i]);
    sort(p+1, p+1+n);

    int mx2 = 0, mn2 = 1e9;
    multiset<int> ms;
    ms.insert(0);
    for(int i=1;i<=n;i++) ms.insert(p[i].fi);
    for(int i=1;i<=n;i++){
        ms.erase(ms.find(p[i].fi));
        int a = min(mn2, p[i].fi);
        int b = max(mx2, max(p[i].fi, *ms.rbegin()));
        ans = min(ans, (mx-mn)*1ll*(b-a));

        mx2 = max(mx2, p[i].se);
        mn2 = min(mn2, p[i].se);
    }

    printf("%lld\n", ans);
}