#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

bool solve(string& s) {
  REP(i, (int)s.size() - 1) {
    if (s[i] == 'A' && s[i + 1] == 'C')
      return true;
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  if (solve(s))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
