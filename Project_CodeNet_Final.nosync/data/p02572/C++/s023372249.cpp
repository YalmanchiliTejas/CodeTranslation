#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
int n;
vector<int> a, s; //s= 累積和

int main() {
  cin >> n;
  s.push_back(0);
  for (int i = 0; i< n; i++) {
    int b;
    cin >> b;
    a.push_back(b);
    s.push_back((s[i] + b) % MOD);
  }
  
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * ((s[n] - s[i+1] + MOD) % MOD);
    ans %= MOD;
  }
  
  cout << ans;
}