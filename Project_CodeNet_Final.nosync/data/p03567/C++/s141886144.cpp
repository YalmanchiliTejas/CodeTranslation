#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;
ul over = 1000000007;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  string s;
  cin >> s;
  for (size_t i=1; i<s.size(); ++i) {
    if (s.substr(i-1, 2)=="AC") {cout << "Yes" << endl; return 0;}
  }
  cout << "No" << endl;
  return 0;
}
