# include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 2;

int n, a[N], u[2][N][N];
long long dp[2][N][N];

long long get(int l, int r, int player){
      if(l == r){
            if(player)
                  return a[l];
            else
                  return -a[l];
      }
      if(u[player][l][r])
            return dp[player][l][r];
      u[player][l][r] = 1;
      if(player){
            dp[player][l][r] = max(get(l + 1, r, player ^ 1) + a[l], get(l, r - 1, player ^ 1) + a[r]);
      } else {
            dp[player][l][r] = min(get(l + 1, r, player ^ 1) - a[l], get(l, r - 1, player ^ 1) - a[r]);
      }
      return dp[player][l][r];
}

int main(){
      cin >> n;

      for(int i = 1; i <= n; i ++){
            cin >> a[i];
      }

      cout << get(1, n, 1);
}
