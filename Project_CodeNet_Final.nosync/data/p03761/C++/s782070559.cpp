#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<array<int, 256>> cnts(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      cnts[i][s[j]]++;
    }
  }

  string result;
  for (char c = 'a'; c <= 'z'; ++c) {
    int min_sz = 50;
    for (int i = 0; i < n; ++i) {
      min_sz = min(min_sz, cnts[i][c]);
    }

    for (int i = 0; i < min_sz; ++i) {
      result += c;
    }
  }

  cout << result << '\n';

  return 0;
}