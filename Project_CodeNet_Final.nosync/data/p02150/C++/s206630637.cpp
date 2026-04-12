#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main(){
  long long a, b, x;
  cin >> a >> b >> x;
  long long ret = x % MOD;
  if(x < a){
    cout << x % MOD << endl;
    return 0;
  }
  long long d = b - a;
  long long n = (x - a) / -d + 1;
  long long l = x + (n-1)*d;
  //cout << d << " " << n << " " << l << endl;
  ret = (ret +  ((n % MOD) *(b % MOD) % MOD)) % MOD;
  cout << ret << endl;
  return 0;
}

