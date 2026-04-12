#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[n + 5][k + 5] = {};
    ll ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int x;
        cin >> x;
        for (int j = 1 ; j <= k - x ; j++) {
            dp[i + 1][j + x] += dp[i][j];
        }
        for (int j = 1 ; j <= k ; j++) {
            dp[i + 1][j] += dp[i][j];
        }
        if (x <= k) {
            dp[i + 1][x] += i + 1;
        }
        for (int j = 1 ; j <= k ; j++) {
            dp[i + 1][j] %= mod;
        }
        ans += dp[i + 1][k];
    }
    cout << ans % mod << endl;
}
