#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  char c;
  set<char> s;

  cin >> c; s.insert(c);
  cin >> c; s.insert(c);
  cin >> c; s.insert(c);

  if (s.size() == 2)  cout << "Yes\n";
  else cout << "No\n";
}
