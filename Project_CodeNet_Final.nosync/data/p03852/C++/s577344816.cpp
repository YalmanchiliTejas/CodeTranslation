#include <bits/stdc++.h>
using namespace std;

int main(){
  char c; //入力
  cin >> c;
  string boinList; //文字列変数
  boinList = "aiueo";
  bool boin;
  
  for(int i=0;i<boinList.size();i++){
    if(boinList.at(i) == c){
      boin = true;
      break;
    } else {
      boin = false;
    }
  }
  
  if(boin){
      cout << "vowel";
  } else {
      cout << "consonant";
  }
}