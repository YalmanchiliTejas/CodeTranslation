#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<double>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<ll> a(n,0);
   rep(i,n) cin >> a[i];
   vvl dp(n+1,vector<ll>(n+1,0));

   for(int k = 1; k <= n; k++)
   {
      for(int i = 0; i+k <= n; i++)
      {
         int j = i+k;
         // 先手番
         if ((n - k) % 2 == 0)
               dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);

         // 後手番
         else
               dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      }
   }

   // rep(i,n+1)
   // {
   //    rep(j,n+1) cout << dp[i][j] << " ";
   //    cout << endl;
   // }
   // 答え
   cout << dp[0][n] << endl;
}
