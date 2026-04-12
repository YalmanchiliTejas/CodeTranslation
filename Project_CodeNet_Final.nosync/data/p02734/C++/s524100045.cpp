#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;
 
int a, dp[4030];
 
int main() {
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        for (int j = s - a; j >= 1; --j) {
            (dp[a + j] += dp[j]) %= mod;
        }
      
      
        (dp[a] += i) %= mod;
        (ans += dp[s]) %= mod;
    }
  
  
    cout << ans << '\n';
    return 0;
}