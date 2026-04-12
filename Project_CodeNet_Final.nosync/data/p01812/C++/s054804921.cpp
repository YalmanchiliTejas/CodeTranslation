#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, K;
  int D[16], idx[101], v[101][101];
  memset(idx, -1, sizeof(idx));
  cin >> N >> M >> K;
  for(int i = 0; i < M; i++) cin >> D[i], D[i]--, idx[D[i]] = i;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < K; j++) cin >> v[i][j], v[i][j]--; 
  }
  int d[1<<16]; memset(d, -1, sizeof(d));
  queue<int> que;
  que.push((1<<M)-1);
  d[(1<<M)-1] = 0;
  while(!que.empty()) {
    int bit = que.front(); que.pop();
    if(!bit) break;
    for(int i = 0; i < K; i++) {
      int nbit = 0;
      for(int j = 0; j < M; j++) {
	if((bit >> j) & 1 && ~idx[v[D[j]][i]]) nbit |= (1<<idx[v[D[j]][i]]);
      }
      if(!~d[nbit]) {
	d[nbit] = d[bit] + 1;
	que.push(nbit);
      }
    }
  }
  cout << d[0] <<endl;
  return 0;
}