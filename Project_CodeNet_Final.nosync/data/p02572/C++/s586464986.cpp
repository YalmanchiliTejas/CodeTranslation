#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll sum = 0,mod = 1000000007;
  int N;
  cin >> N;
  ll A[N];
  rep(i,N) cin >> A[i];
  ll sareru = 0;

  for(int k = N-2;k >= 0;k--){
    sareru += A[k+1];
    sum += (A[k] * (sareru % mod)) % mod;
  }

  // rep(j,N){
  //   littlesum = 0
  //   for(int k = j+1; k<N ; k++){
  //     littlesum += (A[j] * A[k]) % mod;
  //   }
  //   sum += (A[j] * littlesum) % mod;
  // }
  cout << sum % mod << endl;
  return 0;
}