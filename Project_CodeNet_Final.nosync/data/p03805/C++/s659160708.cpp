#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  bool path[N+1][N+1] = {false};
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    
    path[a][b] = true;
    path[b][a] = true;
    
  }
  
  int A[N];
  for (int i = 0; i < N; i++) {
    A[i] = i+1;
  }
  
  int ans = 0;
  do {
    bool cond = true;
    for (int i = 0; i < N-1; i++) {
      if(path[A[i]][A[i+1]]) {
        continue;
      } else {
        cond = false;
      }
    }
    if (cond) ans++;
    
  } while (next_permutation(A+1, A+N));
  
  cout << ans << endl;
}