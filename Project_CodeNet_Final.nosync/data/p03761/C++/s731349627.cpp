#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<string> ss(n);
  for (string &s : ss) cin >> s;

  vector<int> cs(26, 999);
  for (string &s : ss) {
    vector<int> tcs(26, 0);
    for (const char &c : s) {
      tcs[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      cs[i] = min(cs[i], tcs[i]);
    }
  }

  string result = "";
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cs[i]; j++) {
      result += ('a' + i);
    }
  }

  std::cout << result << endl;
  return 0;
}