#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, m[26], s[26];
  cin >> n;
  string S;
  fill(begin(m),end(m),50);
  while (cin >> S) {
    fill(begin(s),end(s),0);
    for (char c : S) ++s[c-'a'];
    for (int i = 0; i != 26; ++i) m[i] = min(m[i], s[i]);
  }
  for (int i = 0; i != 26; ++i) cout << string(m[i], char('a'+i));
  cout << endl;
}
