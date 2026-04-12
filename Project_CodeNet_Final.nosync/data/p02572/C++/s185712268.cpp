#include<stdio.h>
#include<iostream>
using namespace std;
#define MOD 1000000007
int main()
{
  long long sum = 0, a[200005], csum[200005];
  int n;
  cin >> n;
  csum[0] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    csum[i] = (csum[i-1] + a[i]) % MOD;
  }
  
  for(int i = 1; i < n; i++) {
    sum = (sum % MOD + (a[i] * (( (csum[n] - csum[i])%MOD + MOD) % MOD) ) % MOD) % MOD;
  }
  cout << sum % MOD << endl;
  return 0;
}