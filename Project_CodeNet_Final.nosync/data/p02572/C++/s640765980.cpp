#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n;
vector<ll> a(200000);
vector<ll> s(200001); // iまでの累積和
const int MOD = 1e9 + 7;

int main() {
  cin >> n;
  s[0] = 0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    s[i+1] = (s[i] + a[i]);
  }
  
  long long ans = 0;
  for (int i = 0; i < n-1; i++) {
    long long sum = s[n] - s[i+1];
    sum %= MOD;
    ans += (a[i] * sum) % MOD;
  }
  
  cout << ans % MOD << endl;
}