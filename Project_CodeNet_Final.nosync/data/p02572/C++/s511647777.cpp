#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {

  int n;
  cin >> n;

  vector<long long int> a(n);
  vector<long long int> s(n+1, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }

  long long int ans = 0;

  for (int i = 0; i < n; i++) {
    long long int sum = (s[n] - s[i+1]) % 1000000007;
    ans += a[i] * sum;
    ans %= 1000000007;
  }

  cout << ans << endl;

  return 0;

}
