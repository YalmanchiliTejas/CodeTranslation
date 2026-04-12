#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, M, K, D[16], A[100][100];
  int black[100];
  memset(black, -1, sizeof(black));

  cin >> N >> M >> K;
  for(int i = 0; i < M; i++) {
    cin >> D[i];
    black[--D[i]] = i;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < K; j++) {
      cin >> A[i][j];
      --A[i][j];
    }
  }

  int dp[1 << 16];
  fill_n(dp, 1 << 16, -1);
  queue< int > que;
  que.push((1 << M) - 1);
  dp[(1 << M) - 1] = 0;

  while(!que.empty()) {
    int i = que.front();
    que.pop();
    if(i == 0) break;
    for(int j = 0; j < K; j++) {
      int bitMask = 0;
      for(int k = 0; k < M; k++) {
        if((i >> k) & 1 && ~black[A[D[k]][j]]) bitMask |= 1 << black[A[D[k]][j]];
      }
      if(dp[bitMask] == -1) {
        que.push(bitMask);
        dp[bitMask] = dp[i] + 1;
      }
    }
  }
  cout << dp[0] << endl;
}