// KALAM
# include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 77 , M = 100 + 77 , Mod = 1000000007;
char S[N];
int n , d , dp[N][M] , A;
int main(){
   //ios::sync_with_stdio(0);cin.tie(0);
   scanf("%s %d" , S + 1 , & d);
   n = strlen(S + 1);
   dp[0][0] = 1;
   for(int i = 1;i <= n;++ i)
      for(int j = 0;j < d;++ j)
         for(int k = 0;k < 10;++ k){
            int t = ((j - k) % d + d) % d;
            dp[i][j] = (dp[i][j] + dp[i - 1][t]) % Mod;
         }
   for(int i = 1;i < n;++ i)
      for(int j = 1;j < 10;++ j){
         int t = ((- j) % d + d) % d;
         A = (A + dp[i - 1][t]) % Mod;
      }
   int sum = 0;
   for(int i = 1;i <= n;++ i){
      int st = 0;
      if(i == 1)
         ++ st;
      for(;st < S[i] - '0';++ st){
         int t = ((- st - sum) % d + d) % d;
         A = (A + dp[n - i][t]) % Mod;
      }
      sum += S[i] - '0';
   }
   if(sum % d == 0)
      ++ A;
   cout << A % Mod;

   return 0;
}
