#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char S;
  int N = 1;
  
  // ここにプログラムを追記
  cin >> S;
  
  if (S == 'a' || S == 'e' || S == 'i' || S == 'o' || S == 'u') {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}