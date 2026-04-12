#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> E(N, vector<int>(N, 0));
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a][b] =1;
    E[b][a] = 1;
  }
  vector<int> P(N);
  for (int i = 0; i < N; i++){
    P[i] = i;
  }
  int count = 0;
  while (1){
    bool flg = true;
    for (int i = 0; i < N - 1; i++){
      if (E[P[i]][P[i + 1]] == 0){
        flg = false;
      }
    }
    if (flg){
      count++;
    }
    if (!next_permutation(P.begin() + 1, P.end())){
      break;
    }
  }
  cout << count << endl;
}