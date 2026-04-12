#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
int main() {
  cin >> n;
  int a[27][51] = {0}; string S;
  for(int i = 1; i <= n; ++i) {
    cin >> S;
    for(int j = 0; j < S.size(); ++j) ++a[S.at(j)-'a'][i];
  }
  string ans = "";
  for(int i = 0; i < 27; ++i) {
    int cnt = 99;
    for(int j = 1; j <= n; ++j) cnt = min(cnt, a[i][j]);
    if(cnt == 0) continue;
    for(int j = 0; j < cnt; ++j) ans += (char)'a'+i;
  }
  cout << ans << endl;
}