#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
const int MAXN = 123456;
LL step[MAXN], num[MAXN];

int main() {
    LL N, X, M;
    scanf("%lld %lld %lld", &N, &X, &M);
    LL cur = X, idx = 1;
    while (1) {
        if (step[cur]) break;
        step[cur] = idx;
        num[idx] = cur;
        cur = (cur * cur) % M;
        idx++;
    }
    LL offs = 0, cylen = idx - step[cur];
    for (int i = step[cur]; i < idx; i++) offs += num[i];
    LL ans = 0;
    for (LL i = 1; i <= min(N, step[cur] - 1); i++)
        ans += num[i];
    N -= min(N, step[cur] - 1);
    ans += offs * (N / (cylen));
    for (LL i = 0; i < (N % cylen); i++)
        ans += num[i + step[cur]];
    printf("%lld\n", ans);


    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
