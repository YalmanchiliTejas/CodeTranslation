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
  string s;
  cin >> s;
  s.push_back(s[0]);
  s.push_back(s[1]);
  vector<char> t(n + 5);
  
  for(int i = 0; i < 4; i++) {
    if(i < 2) {
      t[0] = 'S';
      t[n + 1] = 'S';
    } else {
      t[0] = 'W';
      t[n + 1] = 'W';
    }
    if(i % 2 == 0) {
      t[1] = 'S';
    } else {
      t[1] = 'W';
    }
    for(int j = 1; j <= n; j++) {
      if(t[j] == 'S') {
        if(s[j] == 'o') {
          t[j + 1] = t[j - 1];
        } else {
          if(t[j - 1] == 'S') {
            t[j + 1] = 'W';
          } else {
            t[j + 1] = 'S';
          }
        }
      } else {
        if(s[j] == 'o') {
          if(t[j - 1] == 'S') {
            t[j + 1] = 'W';
          } else {
            t[j + 1] = 'S';
          }
        } else {
          t[j + 1] = t[j - 1];
        }
      }
    }
    if(t[n] == t[0] && t[n + 1] == t[1]) {
      for(int j = 0; j < n; j++) {
        cout << t[j];
      }
      cout << endl;
      return 0;
    }
    t.clear();
  }
  cout << -1 << endl;
  return 0;
}