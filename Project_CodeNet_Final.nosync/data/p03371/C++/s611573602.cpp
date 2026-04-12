#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <type_traits>
#include <map>

using namespace std;

int a, b, c;
int pizza_a_need, pizza_b_need;

int main(int argc, const char * argv[]) {
  cin >> a >> b >> c >> pizza_a_need >> pizza_b_need;
  int n = max(pizza_a_need, pizza_b_need);
  long long ans = 999999999999999999;
  for(int i = 0; i <= n; i++){
    int pa = i;
    int pb = i;
    long long price = max(0,(pizza_a_need - pa)*a) + max(0,(pizza_b_need - pb)*b) + i*2*c;
    ans = min(ans, price);
  }
  cout << ans << endl;
  return 0;
}
