/* -> Written by <-
   -----------
  |K_A_Z_A_M_A|
  |___________|
  |    _    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#define Task ""
#define F first
#define S second
#define push_back pb
#define bit(x, i) (x >> i) & 1
#define inf 1e9 + 7
#define INF 1e18 + 7

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, a[maxn];
ll s[maxn];

void Solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i-1] + a[i];
    ll res = 0;
    for (int i = 1; i < n; i ++)
    {
        ll ans = (((s[n] - s[i]) % MOD) * a[i]) % MOD;
        res = (res + ans) % MOD;
    }
    cout << res;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    int test_case = 1;
//    cin >> test_case;
    while (test_case --)
        Solve();
    return 0;
}
