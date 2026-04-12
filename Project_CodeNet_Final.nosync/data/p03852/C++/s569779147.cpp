#include <bits/stdc++.h>
using namespace std;

int main(){
  char s;
  cin >> s;
  string v = "aiueo";
  bool b = false;
  for(int i=0;i<5;i++){
    if(v.at(i)==s){
      b = true;
      break;
    }
  }
  if(b){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}