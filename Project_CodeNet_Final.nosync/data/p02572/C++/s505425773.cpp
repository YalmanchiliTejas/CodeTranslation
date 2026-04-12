#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
int main() {
  int n;
  long long sum = 0, ans = 0;
  cin >> n;
  vector< long long > vc(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vc[i];
    sum += vc[i];
  }
  for (int i = 1; i < n; i++) {
    ans += ((sum - vc[i]) % inf * vc[i]) % inf;
    sum -= vc[i];
    ans %= inf;
  }
  cout << ans % inf;
  return 0;
}