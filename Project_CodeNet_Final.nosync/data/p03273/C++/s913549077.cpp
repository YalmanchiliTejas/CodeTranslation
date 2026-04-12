#include <bits/stdc++.h>
using namespace std;

int main(void){
 int H, W;
  cin >> H >> W;
  vector<vector<char>> v(H, vector<char>(W));
  vector<int> H_s, W_s;
  for(int i = 0; i < H; i++){
    int flag = 0;
    for(int j = 0; j < W; j++){
      cin >> v[i][j];
      if(v[i][j] == '#') flag = 1; 
    }
    if(flag == 1) H_s.push_back(i);
  }
  for(int j = 0; j < W; j++){
    int flag = 0;
    for(int i = 0; i < H; i++){
      if(v[i][j] == '#') flag = 1; 
    }
    if(flag == 1) W_s.push_back(j);
  }
  for(int i = 0; i < H_s.size(); i++){
    for(int j = 0; j < W_s.size(); j++){
      cout << v[H_s[i]][W_s[j]];
    }
    cout << endl;
  }

  return 0;
}