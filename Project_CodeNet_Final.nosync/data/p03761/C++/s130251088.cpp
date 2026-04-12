#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<string> s(n);
  string mins = "";
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  string ans = "";

  sort(s[0].begin(), s[0].end());

  for (int i = 0; i < s[0].size(); i++) {
    if (i != 0 && s[0][i] == s[0][i - 1]) continue;  // 同じ文字はスキップ

    string base = s[0];
    char target = base[i];
    int minx = count(base.begin(), base.end(), target);

    for (int j = 1; j < n; j++) {
      string str = s[j];

      int sum = count(str.begin(), str.end(), target);
      minx = min(minx, sum);
    }

    for (int k = 0; k < minx; k++) {
      ans += target;
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans << endl;

  return 0;
}