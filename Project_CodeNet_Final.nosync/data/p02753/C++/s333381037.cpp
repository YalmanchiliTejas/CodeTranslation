#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<int> com(2);
  rep(i, 2) com[i] = 0;
  rep(i, 3)
    if (s[i] == 'A') com[0] = 1;
    else if (s[i] == 'B') com[1] = 1;
  if (com[0]+com[1] < 2) cout << "No";
  else cout << "Yes";
}