#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  vector<char> data = {'a', 'i', 'u', 'e', 'o'};
  bool p = true;
  for (int i = 0; i < 5; i++) {
    if (c == data.at(i)) {
      cout << "vowel" << endl;
     p = false;
      break;
    }
  }
  if (p) {
      cout << "consonant" << endl;
  }
}

