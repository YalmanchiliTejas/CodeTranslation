#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 3*1005;
const int base = 311;
// dung igt thay cho gt luc tinh giai thua
// 10
// cach tao hoan vi tu n so : n*(n+1)/2;

ll a[e];
ll dp[e][e][3];

int main()
{
    ll n, s;
    cin >> n >> s;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    dp[1][0][0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
           (dp[i+1][j][0] += dp[i][j][0]) %= mod;
           (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
           (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
           if(j + a[i] <= s)
           {
               (dp[i+1][j + a[i]][1] = dp[i][j][0] + dp[i][j][1]) %= mod;
               (dp[i+1][j + a[i]][2] = dp[i][j][0] + dp[i][j][1]) %= mod;
           }
        }
    }
    cout << dp[n+1][s][2];

}
