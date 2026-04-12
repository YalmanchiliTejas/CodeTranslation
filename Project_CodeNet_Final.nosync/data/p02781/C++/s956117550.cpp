#include <iostream>
#include <string>
using namespace std;

long long f(string s, int k) {
  int n = s.length();
  if (n < k) return 0;
  if (s[0] == '0') return f(s.substr(1), k);

  if (k == 1)
    return s[0] - '0' + 9 * (n - 1);
  
  long long res = f(s.substr(1), k - 1);
  if (k == 2)
    res += (s[0] - '1') * 9 * (n - 1) + 81 * (n - 1) * (n - 2) / 2;
  else
    res += (s[0] - '1') * 81 * (n - 1) * (n - 2) / 2 + 243 * (n - 1) * (n - 2) * (n - 3) / 2;
  return res;
}

int main() {
  string s;
  cin >> s;
  int k;
  scanf("%d", &k);

  long long ans = f(s, k);
  printf("%lld\n", ans);

  return 0;
}