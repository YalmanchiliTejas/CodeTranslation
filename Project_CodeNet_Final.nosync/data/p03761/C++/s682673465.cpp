#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int n; cin >> n;
  vector<string> str(n);
  for (int i = 0; i < n; i++) cin >> str[i];
  map<char, int> cnt;
  for (int i = 0; i < str[0].length(); i++) {
    cnt[str[0][i]]++;
  }
  for (int i = 1; i < n; i++) {
    int l = str[i].length();
    map<char, int> cnt_tmp;
    for (int j = 0; j < l; j++) {
      cnt_tmp[str[i][j]]++;
    }
    for (int j = 'a'; j < 'a' + 26; j++) {
      cnt[j] = min(cnt[j], cnt_tmp[j]);
    }
  }

  for (int i = 'a'; i < 'a' + 26; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << (char)i;
    }
  }
  cout << endl;
}

