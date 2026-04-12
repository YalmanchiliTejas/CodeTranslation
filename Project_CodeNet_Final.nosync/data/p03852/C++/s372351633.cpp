#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char a;
  cin >> a;
  if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') {
    cout << "vowel\n";
  } else {
    cout << "consonant\n";
  }
}
