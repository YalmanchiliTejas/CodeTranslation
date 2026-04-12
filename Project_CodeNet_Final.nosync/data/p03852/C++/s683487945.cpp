#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;		// c:入力
  string res = "consonant";		// res:結果
  
  cin >> c;		// ｃの入力
  if(c == 'a' || c == 'i' || c=='u' || c=='e' || c=='o'){
    res = "vowel";
  }

  cout << res << endl;
}