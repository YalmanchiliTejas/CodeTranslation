#include <bits/stdc++.h>
using namespace std;
int main(){
  string str = "aeiou";
  char c;
  int i, cnt;
  cin >> c;
  for (i=0; i<5; i++) {
    if (str[i]==c) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}