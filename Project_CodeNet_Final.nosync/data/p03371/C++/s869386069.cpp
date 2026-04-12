#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1<<30;

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int ans = inf;
  for(int i = 0; i <= 1e5; i++) {
    int sum = 2*C*i + max(0, X-i)*A + max(0, Y-i)*B;
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
