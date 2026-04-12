#include "bits/stdc++.h"

#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void Main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2] && s[0] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
