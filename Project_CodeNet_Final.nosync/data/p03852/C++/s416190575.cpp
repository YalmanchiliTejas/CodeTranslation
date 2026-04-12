#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  char c;
  cin >> c;

  string result = "consonant";
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    result = "vowel";
  }

  cout << result << endl;
}
