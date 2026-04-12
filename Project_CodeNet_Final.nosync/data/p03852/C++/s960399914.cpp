#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

int main() {
  char c;
  cin >> c;
  cout << (string("aeiou").find(c) != string::npos ? "vowel" : "consonant") << endl;
}
