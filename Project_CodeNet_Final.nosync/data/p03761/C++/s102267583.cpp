#include <iostream>
#include <array>

using namespace std;

int main() {
  int n;
  array<int, 26> dict, buf;
  string str;

  dict.fill(1<<30);
  buf.fill(0);
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> str;
    int c;
    for (int j=0; j<str.length(); j++) {
      c = str[j];
      buf[c - 0x61] += 1;
    }
    for (int k=0; k<26; k++) {
      dict[k] = min(buf[k], dict[k]);
      buf[k] = 0;
    }
  }

  string ans = "";
  for (int i=0; i<26; i++) {
    for (int j=0; j<dict[i]; j++) {
      ans += (char) i + 0x61;
    }
  }

  cout << ans << endl;

  return 0;
}
