#include<bits/stdc++.h>
using namespace std;
 
int main(){
  char s;
  cin >> s;
  bool Is = false;
  string str1="aiueo";
  for (int a=0; a<5; a++){
    if (str1.at(a) == s){
      cout << "vowel" << endl;
      Is = true;
      break;
    }
  }
  if (Is == false){
    cout << "consonant" << endl;
  }
}