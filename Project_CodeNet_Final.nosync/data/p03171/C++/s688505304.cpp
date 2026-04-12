#include <bits/stdc++.h>
using namespace std;

#define el '\n'

const int MAXN = 3005;

long long dp[MAXN][MAXN]; // dp[i][j] is score to get to set a[i]...a[j]

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  long long a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = n-1; i >= 0; i--){
    for(int j = i; j < n; j++){
      if(i==j){
        dp[i][j] = a[i];
        continue;
      }
      dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);

    }
  }
  cout << dp[0][n-1] << el;
  
  return 0;
}