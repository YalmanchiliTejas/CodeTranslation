#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  string S;
  cin >> S;
  vector<int> c(26);
  rep(i, S.size()) c[S[i]-'a']++;
  for(int i=1; i<n; i++) {
    vector<int> tmp(26);
    cin >> S;
    rep(j, S.size()) tmp[S[j]-'a']++;
    rep(j, 26) c[j] = min(c[j], tmp[j]);
  }
  rep(i, 26) {
    rep(j, c[i])
      cout << char('a'+i);
  }
  cout << endl;
  return 0;
}