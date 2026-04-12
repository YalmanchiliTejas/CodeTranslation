#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  char vowel[5] = {'a', 'i', 'u', 'e', 'o'};

  for (int i=0; i < 5; i++) {
      if (c == vowel[i]) {
          cout << "vowel" << endl;
          return 0;
      }
  }
  cout << "consonant" << endl;
  return 0;
}
