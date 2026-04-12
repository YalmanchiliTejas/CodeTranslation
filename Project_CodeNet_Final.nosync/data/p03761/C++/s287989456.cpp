#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  int i, j;
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<vector<int>> alp(26, vector<int>(n));


  for (i = 0; i < n; i++) {
    for (j = 0; j < s[i].length(); j++) {
      alp[s[i].at(j) - 'a'][i]++;
    }
  }

  for (i = 0; i < 26; i++) {
    sort(alp[i].begin(), alp[i].end());
  }

  for (i = 0; i < 26; i++) {
    for (j = 0; j < alp[i][0]; j++) {
      cout << (char)(i + 'a');
    }
  }

  cout << endl;
  return 0;
}
