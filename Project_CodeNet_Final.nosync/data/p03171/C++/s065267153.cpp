// KALAM
# include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 77;
int n , a[N];
long long dp[N][N][2];
int main(){
   ios::sync_with_stdio(0);cin.tie(0);
   cin >> n;
   for(int i = 1;i <= n;++ i)
      cin >> a[i];
   for(int i = 1;i <= n;++ i)
      dp[i][i][0] = a[i] , dp[i][i][1] = - a[i];
   for(int d = 1;d <= n;++ d){
      for(int i = 1;i + d <= n;++ i){
         int le = i , ri = i + d;
         dp[le][ri][0] = max(dp[le + 1][ri][1] + a[le] , dp[le][ri - 1][1] + a[ri]);
         dp[le][ri][1] = min(dp[le + 1][ri][0] - a[le] , dp[le][ri - 1][0] - a[ri]);
      }
   }
   cout << dp[1][n][0];
   return 0;
}
