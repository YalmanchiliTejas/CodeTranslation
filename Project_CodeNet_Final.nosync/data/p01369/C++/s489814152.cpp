#include <bits/stdc++.h>

using namespace std;

const int al[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
                  1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0};

int main() {
  while (true) {
    string s;
    cin >> s;
    if (s == "#") break;

    bool f = al[s[0] - 'a'];
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (f != al[s[i] - 'a']) {
        f = al[s[i] - 'a'];
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
