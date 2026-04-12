#include <iostream>
#include <string>
using namespace std;

bool h[100];
bool w[100];

int main(){

  int H,W;
  cin >> H >> W;

  string S[100];

  for(int i = 0;i < H;i++)cin >> S[i];




  for(int i = 0;i < H;i++){
    bool flag = true;
    for(int j = 0;j < W;j++){
      if(S[i][j] != '.'){
        flag = false;
        break;
      }
    }
    if(flag)h[i] = true;
  }

  for(int j = 0;j < W;j++){
    bool flag = true;
    for(int i = 0;i < H;i++){
      if(S[i][j] != '.'){
        flag = false;
        break;
      }
    }
    if(flag)w[j] = true;
  }

  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      if(h[i] == false and w[j] == false)cout << S[i][j];
      if(h[i] == false and j == W-1)cout << '\n';
    }
  }

}
