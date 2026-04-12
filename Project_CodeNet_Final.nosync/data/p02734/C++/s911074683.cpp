#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")   */


//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e6 + 51, MOD = 1e9 + 7, mod = 998244353, INF = 2e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int a[N];

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int ans =  0;
    for (int i = 0; i < n; i++) cin >> a[i];
    vi dp(s + 1, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        vi tek(s + 1, 0);
        for (int j = 0; j < s; j++) {
            if (j == 0 && x <= s) {
                tek[x] = i + 1;
            }
            else {
                if (i) {
                    tek[j] += dp[j];
                    if (j + x <= s) {
                        tek[j + x] += dp[j];
                        tek[j + x] %= mod;
                    }
                    tek[j] %= mod;
                }
            }
        }
        dp = tek;
        ans += dp[s] * (n - i);
        //cout << ans << ' ';
        ans %= mod;
    }
    cout << ans;
}
