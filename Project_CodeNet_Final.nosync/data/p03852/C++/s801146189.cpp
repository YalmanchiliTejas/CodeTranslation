#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  cin >> a;
  string boin = "aeiou";
  string result = "consonant";
  
  for (int i = 0; i < boin.size(); i++) {
    if (a == boin.at(i)) {
      result = "vowel";
      break;
    }
  }
  cout << result << endl;
}
