#include <bits/stdc++.h>
using namespace std;

using iter = decltype(cbegin(string()))&;

int num(iter it) {
  assert(isdigit(*it));
  return *it++ - '0';
}
int term(iter it) {
  int res = num(it);
  while (*it == '*') {
    res *= num(++it);
  }
  return res;
}
int expr(iter it) {
  int res = term(it);
  while (*it == '+') {
    res += term(++it);
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n;
  cin >> n;
  auto it = cbegin(s);
  int a = expr(it);
  assert(*it == 0);
  int b = s[0] - '0';
  for (int i = 1; i < (int)s.size(); i += 2) {
    if (s[i] == '+') {
      b += s[i + 1] - '0';
    } else {
      b *= s[i + 1] - '0';
    }
  }
  if (n == a and n == b) {
    cout << "U\n";
  } else if (n == a) {
    cout << "M\n";
  } else if (n == b) {
    cout << "L\n";
  } else {
    cout << "I\n";
  }
}

