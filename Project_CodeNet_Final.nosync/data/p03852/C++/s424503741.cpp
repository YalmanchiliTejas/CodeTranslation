#include <bits/stdc++.h>
using namespace std;

int main() {
  char word;
  cin >> word;
  
  if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u') {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}
