#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
ll dp[3001][3001];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin>>a[i];

   rep(i,n) dp[i][i] = (n%2==1) ? a[i] : -a[i];

   for (int i = 1; i < n; i++){
      for (int j = 0; j+i < n; j++){
         if ((n-i)%2==1)
            dp[j][j+i] = max(dp[j+1][j+i]+a[j]
                           , dp[j][j+i-1]+a[j+i]);
         else
            dp[j][j+i] = min(dp[j+1][j+i]-a[j]
                           , dp[j][j+i-1]-a[j+i]);
      }
   }

   cout << dp[0][n-1] << endl;
}