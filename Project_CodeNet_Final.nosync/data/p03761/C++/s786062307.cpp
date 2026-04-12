#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 114514810893364364;

int main() {
  Int n;
  cin >> n;
  vector<Int> cnt(26, INF);
  for (Int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<Int> x(26, 0LL);
    for (Int j = 0; j < (Int)s.size(); j++) x[s[j] - 'a']++;
    for (Int j = 0; j < 26; j++) cnt[j] = min(cnt[j], x[j]);
  }
  for (Int i = 0; i < 26; i++) {
    if (cnt[i] == INF) continue;
    for (Int j = 0; j < cnt[i]; j++) {
      printf("%c", 'a' + i);
    }
  }
  cout << endl;
  return 0;
}
