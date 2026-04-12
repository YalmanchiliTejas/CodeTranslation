//設定言語check
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
using namespace std;

long long int ansgudge(long long int a){
  if(a >=1000000007) return ansgudge(a - 1000000007);
  else if(a < 0) return ansgudge(a + 1000000007);
  else return a;
}
long long int modinv(long long int a, long long int mod){
  long long int ans = 1 , n = mod - 2 ;
  while(n > 0){
    if(n & 1) ans = (ans * a) % mod ;
    a = (a * a) % mod ;
    n = n >> 1 ;
  }  
  return ans ;
}  

int main(){
  int N, W, M ;
  cin >> N ;
  long long int A[N], total = 0, dob[N], ans = 0 ;
  for(int i=0;i<N;i++){
    cin >> A[i] ;
    dob[i] = (A[i] * A[i]) % 1000000007 ;
    total = (total + A[i]) % 1000000007 ;
  }
  ans = (total * total) % 1000000007 ;
  for(int i=0;i<N;i++){
    ans += (1000000007 - dob[i]) ;
    ans %= 1000000007 ;
  }
  ans = ans * modinv(2ll,1000000007ll) ;
  ans = ans % 1000000007 ;
  cout << ans << endl ;
  return 0 ;
}  