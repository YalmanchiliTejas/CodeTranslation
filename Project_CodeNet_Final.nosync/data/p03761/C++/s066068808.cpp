#include <bits/stdc++.h>
#define inf 99999999
using namespace std;

int n;
string s[55];
int mins[26] = {0};

int main() {
  int i, j;
  char ans;
  cin >> n;
  for(i = 0; i < 26; ++i) mins[i] = inf;
  for(i = 0; i < n; ++i) {
    int now[26] = {0};
    cin >> s[i];
    for(j = 0; j < s[i].size(); ++j) ++now[s[i][j] - 'a'];
    for(j = 0; j < 26; ++j) {
      mins[j] = min(mins[j], now[j]);
    }
  }
  for(i = 0; i < 26; ++i)
    for(j = 0; j < mins[i]; ++j) {
      ans = 'a' + i;
      cout << ans;
    }
  cout << endl;
  return 0;
}