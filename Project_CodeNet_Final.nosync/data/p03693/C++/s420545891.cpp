#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int num = 100*r + 10*g + b;
  if (num % 4 == 0) {
    coYES;
  }
  else {
    coNO;
  }
}
