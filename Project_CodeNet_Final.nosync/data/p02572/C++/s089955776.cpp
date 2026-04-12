#include <iostream>

using namespace std;

const int kM = 1000000007;
int n;
long long s, a, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    ans = (ans + s * a) % kM;
    s = (s + a) % kM;
  }
  cout << ans;
  return 0;
}