#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int min_price = x * a + y * b;
  rep(c_num, max(x * 2, y * 2) + 1) {
    int a_num = max(x - c_num / 2, 0);
    int b_num = max(y - c_num / 2, 0);

    int price = a_num * a + b_num * b + c_num * c;
    min_price = min(price, min_price);
  }

  cout << min_price << endl;
}