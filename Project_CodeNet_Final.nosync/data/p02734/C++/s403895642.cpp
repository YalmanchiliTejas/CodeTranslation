#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 3e3 + 5;
ll mod = 998244353;
ll a[N], dp[N][N], pre[N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(".INP", "r")){
                freopen(".INP", "r", stdin);
                freopen(".OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
                for (int j = k; j >= 1; j--){
                        if (j >= a[i]) {
                                (dp[i][j] = pre[j - a[i]]) %= mod;
                                (pre[j] += dp[i][j]) %= mod;
                        }
                }
                (pre[a[i]] += i) %= mod;
                (dp[i][a[i]] += i) %= mod;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++){
                ans = (ans + dp[i][k] * (n - i + 1)) % mod;
        }
        cout << ans;
}
