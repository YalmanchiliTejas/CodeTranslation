#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<char, int> m, s;
  string S;
  for (char c = 'a'; c <= 'z'; ++c) m[c] = 50;
  while (cin >> S) {
    s.clear();
    for (char c : S) ++s[c];
    for (char c = 'a'; c <= 'z'; ++c) m[c] = min(m[c], s[c]);
  }
  S = "";
  for (char c = 'a'; c <= 'z'; ++c) S += string(m[c], c);
  cout << S << endl;
}
