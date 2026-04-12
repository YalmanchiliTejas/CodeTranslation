#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main(){
  ll N,mod;

  mod = 1000000007;
  cin >> N;
  vector<ll> A(N);
  for(auto& x:A)
    cin >> x;
  
  int i,j;
  ll res = 0;
  ll tmp = 0;
  for(i=N-2;i>=0;i--){
    tmp += A[i+1];
    tmp = tmp % mod;
    res += A[i]*tmp;
    res = res % mod;
  }
  
  
  cout << res << endl;
  
  return 0;
}