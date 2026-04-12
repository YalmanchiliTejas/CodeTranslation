#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

long long a, b, x, c, ans = 0;

int main() {
  cin >> a >> b >> x;
  // (x-a) + (a-b)
  if(x < a)
    ans = x;
  else {
    c = max(0LL, (x - a) / (a - b) + 1);
    ans += (c % N) * (b % N) % N + x % N;
    ans %= N;
  }
  cout << ans % N << endl;
  return 0;
}
