#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int cnt[50][26] = {};
  for (int i = 0; i < n; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < S.size(); j++) {
      cnt[i][S[j] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int tmp = 50;
    for (int j = 0; j < n; j++) {
      tmp = min(tmp, cnt[j][i]);
    }
    for (int j = 0; j < tmp; j++) cout << (char)('a' + i);
  }
  cout << endl;
}