#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int n, k;
string s;

void solve() {
  char t = s[k - 1];
  for (auto c : s) {
    if (c == t)
      cout << c;
    else
      cout << '*';
  }
  cout << endl;
}

int main() {
  cin >> n >> s >> k;
  solve();
}
