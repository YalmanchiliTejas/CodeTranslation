#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  for (int i = 0; i < H; i++) {
    cin >> vec[i];
  }
  
  vector<int> hflag(H, 0);
  vector<int> wflag(W, 0);
  for (int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++){
      if(vec[i][j] == '#'){
        hflag[i] = 1;
        wflag[j] = 1;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if(hflag[i]){
      for(int j = 0; j < W; j++){
        if(wflag[j]){
          cout << vec[i][j];
        }
      }
 	cout << endl; // 末尾なら改行
    }
 }
}
