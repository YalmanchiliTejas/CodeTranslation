/* #                          */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
//#pragma warning(disable:4996)

using namespace std;


/** Type Define **/
typedef long long int           ll;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<string>          vs;
typedef vector<bool>            vb;
typedef vector<int>             vi;
typedef vector<long long>		vl;
typedef vector<vi>              vvi;
typedef vector<vl>				vvl;
typedef vector<char>            vch;

constexpr int               inf = 0x3f3f3f3f;
constexpr long long 		INF = 9123456789123456789;
constexpr long long         MOD = 1000000007LL;
/*************************************************/
vvl dp0, dp1;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();

    dp0.assign(n+1, vl(k+1, 0));
    dp1.assign(n+1, vl(k+1, 0));

    dp0[0][0] = 1;
    for(int i=0; i<n;i++)
        for (int j = 0; j <= k; j++) {
            dp1[i + 1][j] += dp1[i][j];
            if (s[i] == '0') dp0[i + 1][j] += dp0[i][j];
            else             dp1[i + 1][j] += dp0[i][j];
            for (char ch = '1'; ch <= '9'; ch++) {
                if (j + 1 <= k && s[i] == ch) dp0[i + 1][j + 1] += dp0[i][j];
                if (j + 1 <= k) {
                    dp1[i + 1][j + 1] += dp1[i][j];
                    if (ch < s[i])
                        dp1[i + 1][j + 1] += dp0[i][j];
                }
            }
        }

    ll ans = dp0[n][k] + dp1[n][k];
    cout << ans << endl;
    return 0;
}