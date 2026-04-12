//In the name of God

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

const int N = 1e5+10 , mod = 1e9+7 , K = 100;

int pw[N] , dp[N][K];

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   cout << fixed << setprecision(9);
   string s;
   int d;
   cin >> s >> d;
   int n = s.length();
   dp[0][0] = 1;
   for(int i = 1 ; i <= n ; i++){
      for(int j = 0 ; j < 10 ; j++){
         for(int k = 0 ; k < d ; k++)
            (dp[i][k] += dp[i - 1][((k - j) % d + d) % d]) %= mod;
      }
   }
   int ret = 0;
   int nw = 0;
   for(int i = 0 ; i < n ; i++){
      int x = s[i] - 48;
      for(int j = 0 ; j < x ; j++){
         int lst = nw;
         lst += j;
         lst %= d;
         ret += dp[n - 1 - i][(d - lst) % d];
         ret %= mod;
      }
      nw += x;
      nw %= d;
   }
   ret--;
   if(nw == 0)
      ret++;
   cout << (ret + mod) % mod;
   return 0;
}
