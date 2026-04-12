#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

int main() {
  string s; cin >> s;
  cout << (s[0] == s[1] && s[1] == s[2] ? "No" : "Yes") << endl;
}