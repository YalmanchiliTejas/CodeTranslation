#include <bits/stdc++.h>
using namespace std;

int main(){
  long long mnum = 1000000007;
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long btotal = 0;
  long long ans = 0;
  for (int i = n-1; i > 0; i--) {
    btotal += a[i];
    btotal %= mnum;
    ans += btotal * a[i-1] % mnum;
    ans %= mnum;
  }
  cout << ans << endl;
  return 0;
}