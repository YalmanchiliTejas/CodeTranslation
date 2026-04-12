#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  string s;
  map<char, int> ans, t;

cin >> s;
for (auto st : s) ans[st]++;

for (int i = 0; i < n - 1; ++i) {
  t.clear();
  cin >> s;
  for (auto st : s) t[st]++;
  for (char i = 'a'; i <= 'z'; ++i) ans[i] = min(ans[i], t[i]);
  }

for (auto a:ans)
  if (a.second > 0) rep(i, a.second) cout << a.first;
cout << endl;

return 0;
}