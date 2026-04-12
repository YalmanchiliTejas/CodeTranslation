#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for (int i=0; (int)(N); i++)

int main() {
  //ここにコードを書いてください。
  char c;
  cin >> c;
  
  if ((c=='a') || (c == 'i') || (c == 'u') || (c == 'e') || (c == 'o')) {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}
