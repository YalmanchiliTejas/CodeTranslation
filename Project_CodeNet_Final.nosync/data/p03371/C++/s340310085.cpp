#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  vector<int> pattern(3);
  auto max = [](int a, int b){return (a > b) ? a : b;};
  auto min = [](int a, int b){return (a < b) ? a : b;};

  auto hoge = [](int a, int b, int x, int y) {
    if(a > b) {
      return (a - b) * x;
    } else {
      return (b - a) * y;
    }
  };
  pattern[0] = A * X + B * Y;
  pattern[1] = 2 * C * max(X, Y);
  pattern[2] = 2 * C * min(X, Y) + hoge(X, Y, A, B);
  //for(auto x: pattern) cout << x << endl;
  sort(pattern.begin(), pattern.end());
  cout << pattern[0] << endl;
  return 0;
}