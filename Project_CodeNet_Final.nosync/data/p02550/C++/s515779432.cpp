#include <bits/stdc++.h>
using namespace std;
const int LOG = 35;
int main(){
  long long N;
  int X, M;
  cin >> N >> X >> M;
  vector<vector<int>> next(35, vector<int>(M));
  for (int i = 0; i < M; i++){
    next[0][i] = (long long) i * i % M;
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < M; j++){
      next[i][j] = next[i - 1][next[i - 1][j]];
    }
  }
  vector<vector<long long>> sum(35, vector<long long>(M));
  for (int i = 0; i < M; i++){
    sum[0][i] = i;
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < M; j++){
      sum[i][j] = sum[i - 1][j] + sum[i - 1][next[i - 1][j]];
    }
  }
  long long ans = 0;
  for (int i = 0; i < LOG; i++){
    if (N >> i & 1){
      ans += sum[i][X];
      X = next[i][X];
    }
  }
  cout << ans << endl; 
}