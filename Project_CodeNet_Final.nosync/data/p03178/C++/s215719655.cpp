/* 

*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MOD = 1e9+7;
const int MAXN = 10005;
string k;
int n, d;
int dp[MAXN][2][105];

void Add(int& x, int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
}

int DP(int len, bool tight, int modResult)
{
    if(len == n) return (modResult == 0);
    if(dp[len][tight][modResult] != -1) return dp[len][tight][modResult];
    dp[len][tight][modResult] = 0;

    int limit = (tight) ? (k[len]-'0') : 9;

    for(int i = 0; i <= limit; ++i)
    {
        bool nextTight = tight && (i == limit);
        int nextModResult = (((modResult-i) % d) + d) % d;
        Add(dp[len][tight][modResult], DP(len+1, nextTight, nextModResult));
    }

    return dp[len][tight][modResult];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    cin >> k >> d;
    n = k.size();
    memset(dp, -1, sizeof(dp));
    int ans = DP(0, true, 0) - 1;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
    return 0; 
}