#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
 
using namespace std;

void solve()
{
	int a, b, c, x, y;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

	int z = MAX(x, y);
	int i;
	ll ans = LINF;
	for (i = 0; i <= z; i++) {
		ll tmp = i * 2 * c + a * MAX(0, x - i) + b * MAX(0, y - i);
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
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
