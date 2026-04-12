#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int calc(string& s, int i) {
  int res = s[i] - '0';
  while (i + 2 < s.size()) {
    i += 2;
    if (s[i - 1] == '+') res += s[i] - '0';
    else res *= s[i] - '0';
  }
  return res;
}

int term(string& s, int& i) {
  int res = s[i++] - '0';
  while (s[i] == '*') res *= s[++i] - '0', i++;
  return res;
}

int expr(string& s, int& i) {
  int res = term(s, i);
  while (s[i] == '+') i++, res += term(s, i);
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  string s;
  int a;
  cin >> s >> a;  

  int i = 0;
  bool M = expr(s, i) == a, L = calc(s, 0) == a;
  cout << (M && L ? "U" : M ? "M" : L ? "L" : "I") << endl;

  return 0;
}
