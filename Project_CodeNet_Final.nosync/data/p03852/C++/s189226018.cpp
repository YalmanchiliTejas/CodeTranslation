#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;  //英小文字
  cin >> c;  //入力
  
  bool isVowel = false;  //Cが母音であるかどうか（true : 母音である false : 子音である）

 //母音かどうかの判定
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    isVowel = true;
  }

//出力
  if (isVowel) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl; 
  }
}