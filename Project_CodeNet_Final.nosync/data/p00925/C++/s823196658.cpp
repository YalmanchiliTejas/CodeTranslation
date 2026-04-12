#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

string s;
lli x, p;

namespace NS1 {
  lli exp();
  lli term();
  lli fact();

  lli exp() {
    lli x = term();
    while(s[p] == '+') {
      ++p;
      x += term();
    }
    return x;
  }

  lli term() {
    lli x = fact();
    while(s[p] == '*') {
      ++p;
      x *= fact();
    }
    return x;
  }

  lli fact() {
    return s[p++] - '0';
  }
}

namespace NS2 {
  lli exp();
  lli fact();

  lli exp() {
    lli x = fact();
    while(s[p] == '+' || s[p] == '*') {
      if(s[p] == '+') {
        ++p;
        x += fact();
      } else {
        ++p;
        x *= fact();
      }
    }
    return x;
  }

  lli fact() {
    return s[p++] - '0';
  }
}

int main() {
  cin >> s;
  cin >> x;
  s += "$";
  p = 0;
  lli A = NS1::exp();
  p = 0;
  lli B = NS2::exp();
  if(A == x && B == x)
    cout << "U" << endl;
  else if(A == x && B != x)
    cout << "M" << endl;
  else if(A != x && B == x)
    cout << "L" << endl;
  else
    cout << "I" << endl;
  return 0;
}