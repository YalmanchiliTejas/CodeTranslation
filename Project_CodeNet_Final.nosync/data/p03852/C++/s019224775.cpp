#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  string vowels = "aiueo";
  for (int i = 0; i < vowels.size(); i++){
    if (c == vowels.at(i)) {
     cout << "vowel" << endl;
     return 0;
    }
  }
  cout << "consonant" << endl;
}
