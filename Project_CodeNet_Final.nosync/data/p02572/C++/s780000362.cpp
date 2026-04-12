#include<bits/stdc++.h>
using namespace std; 
 
long long MOD = 1000000007;

long long pow(long long x, long long y) {
  long long res = 1; 
  while(y>0) {
    if(y%2)
      res = (res*x)%MOD;
    x = (x*x)%MOD;
    y /= 2; 
  }
  return res;
}

int main() {
  int n;
  long long temp;
  cin >> n; 
  long long sum = 0;
  long long squareSum = 0;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    sum = (sum + temp)%MOD;
    squareSum = (squareSum + (temp*temp)%MOD)%MOD;
  }
  
  sum = (sum*sum)%MOD;
  long long ans = sum - squareSum;
  
  while(ans < 0) {
    ans += MOD;
  }
  
  ans = ans%MOD;
  
  long long twoInverse = pow(2*1LL, MOD-2)%MOD;
  
  cout << (ans*twoInverse)%MOD;
  
  return 0; 
}