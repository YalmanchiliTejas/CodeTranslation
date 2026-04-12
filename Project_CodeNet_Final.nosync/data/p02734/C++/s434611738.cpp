#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 3e3 + 5;
const int mod = 998244353;
const int inf = 1e9 + 9;
 
int a[N], dp[N][N], endat[N][N];

signed main() {
    IOS;
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        endat[i][a[i]] += i;
        for(int j = 0; j <= s; j++){
            dp[i][j] = dp[i-1][j];
            endat[i][j] += endat[i-1][j];
            if(a[i] <= j){
                dp[i][j] += dp[i-1][j-a[i]];
                endat[i][j] += endat[i-1][j-a[i]];
            }
            endat[i][j] %= mod;
            //cout << endat[i][j] << " ";
        }
        //cout << endl;
    }
    for(int i = 1; i <= n; i++){
        ans += ((endat[i][s] - endat[i-1][s] + mod)*(n-i+1)) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
