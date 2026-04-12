#include <iostream>
#include <vector>
using namespace std;
long long mod = 1000000007ll;
int main() {
  int n; 
  cin >> n;
  vector<long long> a(n), cumsum(n);
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    a.at(i) = ai;
    if (i == 0) {
      cumsum.at(i) = ai;
    } else {
      cumsum.at(i) = cumsum.at(i-1) + ai;
    }
    cumsum.at(i) %= mod;
    
  }

  long long ans = 0;

  for (int i = 0; i < n-1; ++i) {
    ans += cumsum.at(i) * a.at(i+1);
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}
