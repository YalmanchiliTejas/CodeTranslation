#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main(){

  long long n;
  cin >> n;

  long long a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  const long long mod = pow(10,9) + 7; //quotient
  long long ans = 0, tmp = 0;

  for(int i=0; i<n-1; i++){
    tmp += a[i];
    tmp = tmp % mod;
    ans += a[i+1] * tmp;
    ans = ans % mod;
  }

  /*
  for(int i=0; i<n-1; i++){
    tmp += a[n-1-i];
    tmp = tmp % mod;
    ans += a[n-2-i] * tmp;
  }

  for(int i=0; i<n; i++){
    ans = ans % mod;
  }
  */


  cout << ans;
}
