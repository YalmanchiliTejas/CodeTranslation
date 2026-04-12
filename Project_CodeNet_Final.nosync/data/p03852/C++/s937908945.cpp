#include<bits/stdc++.h>
using namespace std;

int main(){
  char c;
  string s = "aeiou", flg = "consonant";
  
  cin >> c;
  for(int i = 0;i < s.size();i++){
    if(c == s.at(i)){
      flg = "vowel";
      break;
    }
  }
  cout << flg << endl;
  return 0;
}