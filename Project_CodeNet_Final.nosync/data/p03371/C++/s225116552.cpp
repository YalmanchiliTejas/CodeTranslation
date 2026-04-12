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
#pragma warning(disable:4996) 
 
typedef long long ll;
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
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y); x *= 2; y *= 2;
    int i;
    ll ans = LINF;
    for (i = 0; i <= 200000; i++) {
        ll s = (ll)i*c;
        int x2 = MAX(0,x - i), y2 = MAX(0,y - i);
        s += (ll)(x2 + 1) / 2 * a + (ll)(y2 + 1) / 2 * b;
        ans = MIN(ans, s);
    }
    printf("%lld\n", ans);
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
