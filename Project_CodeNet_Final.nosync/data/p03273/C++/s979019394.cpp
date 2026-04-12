#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> data[i][j];
    }
  }
  vector<int> h(H);
  int x = -1;
  vector<int> w(W);
  int y = -1;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(data[i][j] == '#'){
        x++;
        h[x] = i;
        break;
      }
    }
  }
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(data[j][i] == '#'){
        y++;
        w[y] = i;
        break;
      }
    }
  }
  vector<vector<char>> z(x+1, vector<char>(y+1));
  for(int i = 0; i <= x; i++){
    for(int j = 0; j <= y; j++){
      z[i][j] = data[h[i]][w[j]];
    }
  }
  for(int i = 0; i <= x; i++){
    for(int j = 0; j <= y; j++){
      cout << z[i][j];
    }
    cout << endl;
  }
}
