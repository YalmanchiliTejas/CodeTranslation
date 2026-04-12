#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> H(N), W(N);
  for (int i = 0; i < N; i++){
    cin >> H[i] >> W[i];
  }
  vector<vector<char>> C(4, vector<char>(4));
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cin >> C[i][j];
    }
  }
  string S = "RGB";
  set<pair<int, int>> st;
  for (int i = 0; i < N; i++){
    for (int j = 1 - H[i]; j < 4; j++){
      for (int k = 1 - W[i]; k < 4; k++){
        for (int l = 0; l < 3; l++){
          int add = 0;
          int sub = 0;
          for (int m = 0; m < H[i]; m++){
            for (int n = 0; n < W[i]; n++){
              int y = j + m;
              int x = k + n;
              if (0 <= y && y < 4 && 0 <= x && x < 4){
                if (C[y][x] == S[l]){
                  add |= 1 << (y * 4 + x);
                } else {
                  sub |= 1 << (y * 4 + x);
                }
              }
            }
          }
          st.insert(make_pair(add, sub));
        }
      }
    }
  }
  vector<int> d(65536, -1);
  d[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int c = Q.front();
    Q.pop();
    for (auto P : st){
      int c2 = c & ~P.second | P.first;
      if (d[c2] == -1){
        d[c2] = d[c] + 1;
        Q.push(c2);
      }
    }
  }
  cout << d[65535] << endl;
}
