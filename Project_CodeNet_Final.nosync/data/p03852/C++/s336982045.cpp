#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  string answer;
  if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
    answer = "vowel";
  } else {
    answer = "consonant";
  }
  cout << answer << endl;
}
