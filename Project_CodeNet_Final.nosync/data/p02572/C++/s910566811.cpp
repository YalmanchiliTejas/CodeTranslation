#include <iostream>
using namespace std;

int main() {
  long n;
  cin >> n;
  long long a[n], s[n+1];
  s[0] = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }
  
  long long result = 0;
  for (long long i = 0; i < n; i++) {
    result += a[i]*((s[n] - s[i+1]) % 1000000007);
    if (result >= 1000000007) result %= 1000000007;
  }
  
  cout << result;
  
  return 0;
}