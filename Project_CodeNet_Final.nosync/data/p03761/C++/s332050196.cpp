#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
string s[60];
int cnt[60][26];

void solve() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<s[i].size();j++) {
      cnt[i][s[i][j] - 'a']++;
    }
  }
  for (int i=0;i<26;i++) {
    int minCnt = 60;
    for (int j=0;j<n;j++) {
      minCnt = min(minCnt, cnt[j][i]);
    }
    for (int j=0;j<minCnt;j++) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> s[i];
  }
  solve();
}
