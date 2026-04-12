#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> A(n);
  vector<long long> B(n);
  long long x = 0, mod = 1000000007, b=0, t=0;
  for(int i=0; i<n; i++){
    cin >> A[i];
    b += A[i];
    b %= mod;
    B[i] = b;
  }
  for(int i=0; i<n-1; i++){
    if(b>B[i]) t = b - B[i];
    else t = b - B[i] + mod;
    x += A[i]*t;
    x %= mod;
  }
  cout << x;
}
