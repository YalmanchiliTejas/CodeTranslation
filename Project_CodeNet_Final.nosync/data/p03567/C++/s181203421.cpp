#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  regex re(R"(AC)");
  smatch m;

  bool ans = regex_search(s, m, re);

  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}