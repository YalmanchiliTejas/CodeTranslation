#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(26, 1e9);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> temp(26, 0);
    for (int j = 0; j < s.size(); j++) temp[s[j] - 'a']++;
    for (int j = 0; j < 26; j++) {
      cnt[j] = min(cnt[j], temp[j]);
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << char('a' + i) << flush;
    }
  }
  cout << endl;
  return 0;
}