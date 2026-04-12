#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = (1e9);
int main(){
  int N;
  const int M = (1<<16);
  cin >> N;
  vector<int> DP(M,INF);
  DP[0] = 0;
  string color = "RGB";
  vector<int> H(N), W(N);
  for(int i = 0; i < N; ++i){
    cin >> H[i] >> W[i];
  }
  string C[4];
  for(int i = 0; i < 4; ++i) cin >> C[i];

  int AND[5][5][7][7][3], OR[5][5][7][7][3];
  for(int j = 0; j < N; ++j){
    for(int k = 0; k < 3; ++k){
      for(int l = 1-H[j]; l < 4; ++l){
        for(int m = 1-W[j]; m < 4; ++m){
          int a = M-1, o = 0;
          for(int h = max(-l,0); h < H[j]; ++h){
            for(int w = max(-m,0); w < W[j]; ++w){
              int x = l+h, y = m+w;
              if(x > 3 || y > 3 || x < 0 || y < 0) continue;
              if(C[x][y] == color[k]) o |= (1<<(4*x+y));
              else a &= ~(1<<(4*x+y));
            }
          }
          AND[H[j]][W[j]][l+3][m+3][k] = a;
          OR[H[j]][W[j]][l+3][m+3][k] = o;
        }
      }
    }
  }
  priority_queue< pair<int,int> > wait;
  wait.emplace(0,0);
  while(!wait.empty()){
    int c = -wait.top().first, i = wait.top().second;
    wait.pop();
    if(DP[i] < c) continue;
    DP[i] = c;
    if(i == M-1) break;
    for(int j = 0; j < N; ++j){
      for(int k = 0; k < 3; ++k){
        for(int l = 1-H[j]; l < 4; ++l){
          for(int m = 1-W[j]; m < 4; ++m){
            int i_ = i;
            i_ &= AND[H[j]][W[j]][l+3][m+3][k];
            i_ |= OR[H[j]][W[j]][l+3][m+3][k];
            if(DP[i_] <= DP[i]+1) continue;
            DP[i_] = DP[i]+1;
            wait.emplace(-c-1,i_);
          }
        }
      }
    }
  }
  cout << DP[M-1] << endl;
  return 0;
}

