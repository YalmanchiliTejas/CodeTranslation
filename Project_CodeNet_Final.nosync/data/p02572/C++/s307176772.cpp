#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  ll n;
  cin >> n;
  ll a[n];
  int mod = 1000000007;
  ll sum = 0;
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }
  ll b[n+1] = {};
  for(int i = 1;i<n+1;i++){
    b[i] = b[i-1] + a[i-1];
    //b[i] %= mod;
  }
  
  ll tmp;
  for(int i = 0;i<n;i++){
    tmp = (b[n]-b[i+1])%mod;
    sum += a[i]*tmp%mod;  
    sum%=mod;
  }

  cout << sum;
}