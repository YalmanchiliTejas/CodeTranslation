#include <iostream>

using namespace std;

int main(){
  int a, b, c, x, y;
  int common_pizza, common_price, extra_pizza, extra_tanka, extra_price;
  cin >> a >> b >> c >> x >> y;
  common_pizza = x < y?x:y;
  common_price = a + b < 2*c?(a+b)*common_pizza:2*c*common_pizza;
  extra_pizza = x < y?y-common_pizza:x-common_pizza;
  extra_tanka = x < y?b:a;
  if (extra_tanka > 2*c) {
    extra_tanka = 2*c;
  }
  extra_price = extra_tanka * extra_pizza;
  cout << common_price + extra_price << endl;
  return(0);
}
