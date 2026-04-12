#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<int>> v(H,vector<int>(W));//
  vector<bool> tate(W,false);
  vector<bool> yoko(H,false);
  vector<string> ans(H,"");
  for(int i = 0; i < H;i++){
    string str= {""};
    cin >> str;
    ans[i].append(str);
    for(int j = 0; j< W;j++){
      if(ans[i][j] == '#'){
        tate[j] = true;
        yoko[i] = true;
      }
    }
 }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(tate[j]&&yoko[i])cout << ans[i][j];
    }
    if(yoko[i])cout << endl;
  }
  cout << endl;
}