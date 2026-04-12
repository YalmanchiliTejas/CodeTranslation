#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ );
using namespace std;
const long long mod = 1000000007;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  long long n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a.at(i);
    sum += a.at(i);
    sum %= mod;
  }
  long long ans = 0;
  for(int i = 0; i < n; i++){
    sum -= a.at(i);
    if (sum < 0) sum += mod;
    long long num  = (a.at(i)*sum)%mod;
    num %= mod;
    ans += num;
    ans %= mod;
  }
  ans %= mod;
  cout << ans << endl;
}