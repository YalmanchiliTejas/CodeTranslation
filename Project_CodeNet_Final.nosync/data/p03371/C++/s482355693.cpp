#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

  int result = 0;
  if (A+B>=C*2) {
    if (X>=Y) result = C*2*Y + min(A, C*2)*(X-Y);
    else result = C*2*X + min(B, C*2)*(Y-X);
  }
  else result = A*X + B*Y;

  cout << result << endl;
  return 0;
}