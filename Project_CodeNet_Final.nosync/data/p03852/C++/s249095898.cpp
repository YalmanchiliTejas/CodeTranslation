#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  cin >> S;
  string vowel = "vowel";
  string consonant = "consonant";
  string vowelStr = "aeiou";
  for (int i = 0; i < vowelStr.size() ; i++) {
    if (S == vowelStr.at(i)){
      cout << vowel << endl;
      return 0;
    }
  }
  cout << consonant << endl;

}
