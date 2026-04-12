#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  cin >> n;

  vector<int> memo(26);

  string s;
  cin >> s;

  for (int i = 0; i < (int)s.size(); i++) {
    memo[s[i] - 97]++;
  }

  for (int i = 1; i < n; i++) {
    cin >> s;

    vector<int> kari(26);

    for (int i = 0; i < (int)s.size(); i++) {
      kari[s[i] - 97]++;
    }

    for (int i = 0; i < 26; i++) {
      memo[i] = min(memo[i], kari[i]);
    }
  }

  int i = 0;
  while (i < 26) {
    while (memo[i] > 0) {
      char c = i + 97;
      cout << c;
      memo[i]--;
    }
    i++;
  }
  return 0;
}