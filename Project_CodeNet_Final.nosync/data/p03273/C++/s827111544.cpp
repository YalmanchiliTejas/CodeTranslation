#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int H,W;
  cin >> H >> W;
  char x[H][W];

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> x[i][j];
    }
  }

  vector<bool> h(H,false);
  vector<bool> w(W,false);

  for(int i = 0; i < H; i++){
    // 行方向チェック
    for(int j = 0; j < W; j++){
      if(x[i][j] == '#'){
        h[i] = true; // i列目は残す
        break;
      }
    }
  }

  for(int j = 0; j < W; j++){
    // 列方向チェック
    for(int i = 0; i < H; i++){
      if(x[i][j] == '#'){
        w[j] = true; // j行目は残す
        break;
      }
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(h[i] && w[j]){
        cout << x[i][j];
      } 
    }
    if(h[i]) cout << endl;
  }
}

