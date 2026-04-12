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
 
  int min_price = x * a + b * y;
  rep(a_num, x + 1) {
    int min_c_num = max((x - a_num) * 2, 0);
 
    int price_with_b = a_num * a + max((y - min_c_num / 2), 0) * b + min_c_num * c;
    int price_without_b = a_num * a + max(min_c_num, y * 2) * c;
 
    int price = min(price_with_b, price_without_b);
    if(price == 110000000) {
 
    }
 
    min_price = min(min_price, price);
  }
 
  cout << min_price << endl;
}