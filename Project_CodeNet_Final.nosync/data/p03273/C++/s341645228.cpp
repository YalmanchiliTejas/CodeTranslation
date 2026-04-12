//B.cpp
#include <iostream>
#include <string>
using namespace std;

int chk;

int main(){
  int H,W;
  cin >> H >> W;
  string S[H];
  for(int i = 0; i < H; i++){
    cin >> S[i];
  }

  bool flag;
  int l = 0;
  chk = W;

  while(l<W){
    flag = true;
    for(int j = 0; j < H; j++){
      if(S[j][l]!='.'){
        flag = false;
        break;
      }
    }
    if(flag){
      for(int k = 0; k < H; k++){
        S[k].erase(S[k].begin()+l);
      }
      --chk;
    }else{
      ++l;
    }
  }

  for(int i = 0; i < H; i++){
    if(S[i]==string(chk,'.')){
      S[i] = "";
    }
  }

  for(int i = 0; i < H; i++){
    if(S[i]!="") cout << S[i] << endl;
    else cout << S[i];
  }

  return 0;
}
