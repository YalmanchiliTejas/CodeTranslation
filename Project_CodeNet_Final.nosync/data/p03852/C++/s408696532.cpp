#include <bits/stdc++.h>

using namespace std;

int main(){
  char c;
  string boin = "aeiou";
  cin >> c;
  
  bool flag = false;
  
  for (const auto& i: boin){
    if (i == c){
      flag = true;
    }
  }
  if (flag) {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}