#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;



void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    int xmin = INF, xmax = -INF;
    int ymin = INF, ymax = -INF;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        if (x[i] > y[i]) swap(x[i], y[i]);
        xmin = MIN(xmin, x[i]);
        xmax = MAX(xmax, x[i]);
        ymin = MIN(ymin, y[i]);
        ymax = MAX(ymax, y[i]);
    }

    ll ans = ((ll)xmax - xmin)*((ll)ymax - ymin);

    vector<pair<int, int> > z;
    for (i = 0; i < n; i++) {
        z.push_back(make_pair(x[i], y[i]));
    }
    sort(z.begin(), z.end());

    vector<int> ymin0(n), ymax0(n);
    for (i = 0; i < n; i++) {
        if (i == 0) {
            ymin0[i] = ymax0[i] = z[i].second;
        }
        else {
            ymin0[i] = MIN(ymin0[i - 1], z[i].second);
            ymax0[i] = MAX(ymax0[i - 1], z[i].second);
        }
    }

    vector<int> xmin0(n), xmax0(n);
    for (i = n-1; i >= 0; i--) {
        if (i == n-1) {
            xmin0[i] = xmax0[i] = z[i].first;
        }
        else {
            xmin0[i] = MIN(xmin0[i + 1], z[i].first);
            xmax0[i] = MAX(xmax0[i + 1], z[i].first);
        }
    }

    for (i = 0; i < n-1; i++) {
        int min = MIN(ymin0[i], xmin0[i + 1]);
        int max = MAX(ymax0[i], xmax0[i + 1]);
        ll tmp = ((ll)ymax-xmin)*((ll)max - min);
        ans = MIN(ans, tmp);
    }

    printf("%lld\n", ans);
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

