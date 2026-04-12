#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef long double ld;

const int N = 3e5+10 , mod = 1e9+7;

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int n;
   cin >> n;
   int a[3 * n];
   for(int i = 0 ; i < 3 * n ; i++)
      cin >> a[i];
   int dp[n + 1][n + 1] , mxx[n + 1] , hlp[n + 1][n + 1];
   for(int i = 0 ; i < n + 1 ; i++){
      mxx[i] = -mod;
      for(int j = 0 ; j < n + 1 ; j++)
         dp[i][j] = hlp[i][j] = -mod;
   }
   dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
   int add = 0;
   int mx = 0;
   mxx[a[0]] = mxx[a[1]] = 0;
   for(int i = 2 ; i < 3 * n - 1 ; i += 3){
      if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
         add++;
         continue;
      }
      vector <pii> v;

      hlp[a[i + 1]][a[i + 2]] = max(hlp[a[i + 1]][a[i + 2]] , dp[a[i]][a[i]] + 1);
      v.push_back({a[i + 1] , a[i + 2]});
      hlp[a[i]][a[i + 2]] = max(hlp[a[i]][a[i + 2]] , dp[a[i + 1]][a[i + 1]] + 1);
      v.push_back({a[i] , a[i + 2]});
      hlp[a[i]][a[i + 1]] = max(hlp[a[i]][a[i + 1]] , dp[a[i + 2]][a[i + 2]] + 1);
      v.push_back({a[i] , a[i + 1]});

      if(a[i] == a[i + 2]){
         for(int j = 1 ; j <= n ; j++){
            hlp[j][a[i + 1]] = max(hlp[j][a[i + 1]] , dp[j][a[i]] + 1);
            v.push_back({j , a[i + 1]});
         }
      }
      if(a[i] == a[i + 1]){
         for(int j = 1 ; j <= n ; j++){
            hlp[j][a[i + 2]] = max(hlp[j][a[i + 2]] , dp[j][a[i]] + 1);
            v.push_back({j , a[i + 2]});
         }
      }
      if(a[i + 1] == a[i + 2]){
         for(int j = 1 ; j <= n ; j++){
            hlp[j][a[i]] = max(hlp[j][a[i]] , dp[j][a[i + 1]] + 1);
            v.push_back({j , a[i]});
         }
      }

      for(int j = 0 ; j <= 2 ; j++)
         for(int k = j + 1 ; k <= 2 ; k++){
            hlp[a[i + j]][a[i + k]] = max(hlp[a[i + j]][a[i + k]] , mx);
            v.push_back({a[i + j] , a[i + k]});
         }

      for(int j = 0 ; j <= 2 ; j++){
         for(int k = 1 ; k <= n ; k++){
            hlp[a[i + j]][k] = max(hlp[a[i + j]][k] , mxx[k]);
            v.push_back({a[i + j] , k});
         }
      }

      for(pii x : v){
         dp[x.first][x.second] = dp[x.second][x.first] = max(dp[x.first][x.second] , hlp[x.first][x.second]);
         mxx[x.first] = max(mxx[x.first] , dp[x.first][x.second]);
         mxx[x.second] = max(mxx[x.second] , dp[x.first][x.second]);
         mx = max(mx , dp[x.first][x.second]);
      }
      /*for(int i = 1 ; i <= n ; i++)
         for(int j = i ; j <= n ; j++)
            cout << i << " " << j << " " << dp[i][j] << endl;
      cout << "-----------------" << endl;*/
   }
   dp[a[3 * n - 1]][a[3 * n - 1]]++;
   int ans = 0;
   for(int i = 1 ; i <= n ; i++)
      for(int j = 1 ; j <= n ; j++)
         ans = max(ans , dp[i][j]);
   cout << ans + add;
   return 0;
}
