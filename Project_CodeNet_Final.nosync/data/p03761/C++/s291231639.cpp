#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<vector<int>> mp(n, vector<int>(200));
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < s[i].length(); j++) {
      mp[i][s[i][j]]++;
    }
  }

  vector<int> ans(200, 0);
  for(int i = 0; i < 200; i++) {
    ans[i] = mp[0][i];
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 200; j++) {
      if(ans[j] > 0) {
        ans[j] = min(ans[j], mp[i][j]);
      }
    }
  }
  for(int i = 0; i < 200; i++) {
    while(ans[i] > 0) {
      cout << (char)i;
      ans[i]--;
    }
  }
  cout << endl;
  return 0;
}