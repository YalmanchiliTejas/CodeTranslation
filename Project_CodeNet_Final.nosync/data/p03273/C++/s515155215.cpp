#include <iostream>
#include <vector>

using namespace std;
int H, W;

int compress(int depth, int maxd, vector<vector<char>> &V){
  if(depth == maxd) return 1;
  
  int f = 0;
  for(int i = 0; i < H; i++){
    if(V[i][depth % W] == '#') f = 1;
  }
  if(f == 0){
    //フラグが立ってない場合塗りつぶす
    for(int i = 0; i < H; i++){
      V[i][depth % W] = 'x';
    }
  }
    
  f = 0;  
  for(int j = 0; j < W; j++){
    if(V[depth % H][j] == '#') f = 1;
  }
  if(f == 0){
    //フラグが立ってない場合塗りつぶす
    for(int j = 0; j < W; j++){
      V[depth % H][j] = 'x';
    }
  }
  return compress(depth + 1, maxd, V);
}

int main(){
  cin >> H >> W;
  int maxd = max(H ,W);
  //cout << maxd;
  vector<vector<char>> V(H, vector<char>(W, 'a'));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> V[i][j];
    }
  }
  
  compress(0, maxd, V);
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(V[i][j] == 'x') continue;
      cout << V[i][j];
    }
    //if(V[i][0] == 'x') continue;
    cout << endl;
  }
}
