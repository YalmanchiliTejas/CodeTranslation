#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
pii P[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int mn = 1e9, mx = 0, mxx = 0, mny = 1e9;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i].fs >> P[i].se;
        if (P[i].fs > P[i].se) swap(P[i].fs, P[i].se);
        mn = min(mn, P[i].fs);
        mxx = max(mxx, P[i].fs);
        mx = max(mx, P[i].se);
        mny = min(mny, P[i].se);
    }
    sort(P + 1, P + (n + 1));
    llong ans = (llong)(mxx - mn) * (mx - mny);
    multiset<int> sp;
    for (int i = 1; i <= n; ++i) sp.insert(P[i].fs);
    for (int i = 0; i <= n; ++i) {
        if (i) {
            sp.insert(P[i].se);
            sp.erase(sp.find(P[i].fs));
        }
        ans = min(ans, (llong)(mx - mn) * (*sp.rbegin() - *sp.begin()));
    }
    printf("%lld\n", ans);
    return 0;
}