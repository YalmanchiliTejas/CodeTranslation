#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> al(26, 50);
  for (int i = 0; i < n; i++) {
    string S;
    cin >> S;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int cnt = 0;
      for (int j = 0; j < S.size(); j++) {
        if (ch == S[j]) cnt++;
      }
      al[ch - 'a'] = min(al[ch - 'a'], cnt);
    }
  }

  string ans = "";
  for (int i = 0; i < 26; i++) {
    int num = al[i];
    for (int j = 0; j < num; j++) {
      ans += 'a' + i;
    }
  }

  cout << ans << endl;
}