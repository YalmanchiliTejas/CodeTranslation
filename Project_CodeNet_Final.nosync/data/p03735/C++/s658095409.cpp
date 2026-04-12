/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 2e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

pll point[maxn];
ll suffix_max[maxn], suffix_min[maxn];

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &point[i].Fi, &point[i].Se);
        if (point[i].Fi > point[i].Se) swap(point[i].Fi, point[i].Se);
    }
    sort(point + 1, point + 1 + n);
    ll ans = LL_INF;
    ll rmax = 0, rmin = LL_INF;
    ll bmax = 0, bmin = LL_INF;

    // Case I
    int ida = 0, idb = 0;
    for (int i = 1; i <= n; i++) {
        if (point[i].Fi < bmin) {
            bmin = point[i].Fi;
            ida = i;
        }
        if (point[i].Se > rmax) {
            rmax = point[i].Se;
            idb = i;
        }
    }
    bmax = bmin, rmin = rmax;
    for (int i = 1; i <= n; i++) {
        if (i == ida || i == idb) {
            if (ida == idb) continue;
            if (i == ida) {
                rmin = min(rmin, point[i].Se);
            } else {
                bmax = max(bmax, point[i].Fi);
            }
        } else {
            rmin = min(rmin, point[i].Se);
            bmax = max(bmax, point[i].Fi);
        }
    }
    ans = min(ans, (rmax - rmin) * (bmax - bmin));

    // Case II
    rmax = 0, rmin = LL_INF;
    bmax = 0, bmin = LL_INF;
    ida = 1, idb = 0;
    rmin = point[1].Fi;
    for (int i = n; i >= 1; i--) {
        if (point[i].Se > rmax) {
            rmax = point[i].Se;
            idb = i;
        } else if (point[i].Se == rmax) {
            if (i != ida) idb = i;
        }
    }
    memset(suffix_min, 0x3f, sizeof(suffix_min));
    if (ida != idb) {
        for (int i = n; i >= 1; i--) {
            if (i == ida) {
                suffix_max[i] = max(suffix_max[i + 1], point[i].Se);
                suffix_min[i] = min(suffix_min[i + 1], point[i].Se);
            } else if (i == idb) {
                suffix_max[i] = max(suffix_max[i + 1], point[i].Fi);
                suffix_min[i] = min(suffix_min[i + 1], point[i].Fi);
            } else {
                suffix_max[i] = max(suffix_max[i + 1], point[i].Fi);
                suffix_min[i] = min(suffix_min[i + 1], point[i].Fi);
            }
        }
        ll minvalue = LL_INF;
        for (int i = 1; i <= n; i++) {
            if (i == ida) {
                bmax = max(bmax, point[i].Se);
                bmin = min(bmin, point[i].Se);
            } else if (i == idb) {
                bmax = max(bmax, point[i].Fi);
                bmin = min(bmin, point[i].Fi);
            } else {
                ll newbmax = max(bmax, max(point[i].Fi, suffix_max[i + 1]));
                ll newbmin = min(bmin, min(point[i].Fi, suffix_min[i + 1]));
                ll oldbmax = max(bmax, max(point[i].Se, suffix_max[i + 1]));
                ll oldbmin = min(bmin, min(point[i].Se, suffix_min[i + 1]));;
                if (newbmax - newbmin < oldbmax - oldbmin) {
                    bmax = max(bmax, point[i].Fi);
                    bmin = min(bmin, point[i].Fi);
                } else {
                    bmax = max(bmax, point[i].Se);
                    bmin = min(bmin, point[i].Se);
                }
            }
        }
        ans = min(ans, (rmax - rmin) * (bmax - bmin));
    }
    printf("%lld\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
