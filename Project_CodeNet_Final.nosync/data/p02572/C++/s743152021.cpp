#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long  pMod = 1000000007;
  long long  a[n];
  long long  tempsum = 0;
  long long  sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    tempsum += a[i];
    tempsum %= pMod;
  }
  for(int i = 0; i < n; i++) {
    tempsum -= a[i];
    if(tempsum < 0) tempsum += pMod;
    sum += tempsum * a[i];
    sum %= pMod;
  }
  cout << sum << endl;
}