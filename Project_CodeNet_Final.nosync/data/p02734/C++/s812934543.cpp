#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    ll dp[n+5][s+5] = {};
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        int add;
        cin >> add;
        for (int j = 0 ; j <= s ; j++) {
            dp[i][j] = dp[i-1][j];
            if (j == add) {
                dp[i][j] += i;
            }
            if (j >= add) {
                dp[i][j] += dp[i-1][j-add];
            }
            dp[i][j] %= mod;
        }
        ans += (dp[i][s] - dp[i-1][s] + mod) * (n - i + 1);
        ans %= mod;
    }
    cout << ans << '\n';
}