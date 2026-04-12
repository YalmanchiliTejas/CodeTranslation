#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  if (c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u'){
    string vowel = "vowel";
    cout << vowel << endl;
  } else {
    string consonant = "consonant";
    cout << consonant << endl;
  }
}