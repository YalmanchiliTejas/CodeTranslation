#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  // ここにプログラムを追記
  string result = "consonant";
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      result = "vowel";
  }

  cout << result << endl;
}
