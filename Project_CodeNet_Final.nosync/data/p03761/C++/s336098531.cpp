#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 100005;

int main() {
  int n;
  cin >> n;

  vector<int> alp(26, INF);
  for (int i = 0; i < n; i++) {
    vector<int> tmp(26, 0);
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.size(); j++) {
      int num = s[j] - 'a';
      tmp[num]++;
    }
    for (int i = 0; i < 26; i++) {
      alp[i] = min(alp[i], tmp[i]);
    }
  }

  if (*max_element(alp.begin(), alp.end()) == 0) {
    return 0;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < alp[i]; j++) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;

  return 0;
}