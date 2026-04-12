#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long  A, B, C, X, Y;

  cin >> A >> B >> C >> X >> Y;

  int max_loop = max(X, Y);
  long long ans = 100000000000;
  long long money;
  
  for (long long i = 0; i <= max_loop; i++) {
    if ((X-i) >= 0 and (Y-i) >= 0) {
      money = A * (X-i) + B * (Y-i) + C * 2 * i;
    } else {
      if (X < i) {
	money = B * (Y-i) + C * 2 * i;
      } else {
	money = A * (X-i) + C * 2 * i;
      }
    }
    ans = min(money, ans);
  }

  cout << ans << endl;

  return 0;
}
