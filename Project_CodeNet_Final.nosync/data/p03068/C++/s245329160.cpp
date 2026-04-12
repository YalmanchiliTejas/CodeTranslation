#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  string s;
  cin >> n >> s >> k;

  char sk = s[k - 1];
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != sk) {
      s[i] = '*';
    }
  }

  cout << s << '\n';
}