#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template<class T, class T2> inline bool chkmax(T &x, const T2 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T2> inline bool chkmin(T &x, const T2 &y) { return x > y ? x = y, 1 : 0; }
const ll mod = 998244353;
template<class T> inline void fix(T &x) {if(x >= mod | x <= -mod) {x %= mod;} if(x < 0) {x += mod;}}

const int MAX_N = 3e3 + 10;
ll dp[MAX_N][MAX_N], sum[MAX_N], arr[MAX_N];

signed main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        dp[i][0] ++;
        for(int j = 0; j <= s; j ++) {
            if(j >= arr[i]) {
                dp[i][j] += dp[i - 1][j - arr[i]];
            }
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
        }
        for(int j = 0; j < MAX_N; j ++) {
            sum[j] += dp[i][j]; sum[j] %= mod;
        }
    }
    cout << sum[s];
    return 0;
}


