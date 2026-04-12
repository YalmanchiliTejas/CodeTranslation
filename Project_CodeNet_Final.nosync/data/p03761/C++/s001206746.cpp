#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int cnt[s[0].size()];
  for (int i = 0; i < s[0].size(); i++) cnt[i] = 0;
  for (int i = 0; i < s[0].size(); i++) {
    for (int j = 1; j < n; j++) {
      for (int k = 0; k < s[j].size(); k++) {
        if (s[0][i] == s[j][k]) {
          s[j][k] = 'A';
          cnt[i]++;
          break;
        }
      }
    }
  }
  string ans = "";
  for (int i = 0; i < s[0].size(); i++) {
    if (cnt[i] == n - 1) ans += s[0][i];
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;
}
