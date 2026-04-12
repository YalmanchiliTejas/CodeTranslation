#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
    
  ll dp[3100][3100];
  
  for (int i = 0; i < N; i++) {
    dp[i][i] = 0;
  }
  
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N-i; j++) {
      
      if ((N-i) % 2) {
        dp[j][j+i] = min(dp[j][j+i-1] - a[j+i-1], dp[j+1][j+i] - a[j]);
      } else {
        dp[j][j+i] = max(dp[j][j+i-1] + a[j+i-1], dp[j+1][j+i] + a[j]);      
      }
    }
      
  }

  
  cout << dp[0][N] << endl;
  
}