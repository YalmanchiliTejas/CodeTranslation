#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  char c;
  cin >> c;

  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    puts("vowel");
  } else {
    puts("consonant");
  }

  return 0;
}