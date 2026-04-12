#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

long long comb(const long long a, const long long b){
  long long mod = 1000000007;

  long long fact[a + 1];
  long long inv[a + 1];
  fact[0] = 1;
  inv[0] = 1;

  for(long long i = 1; i <= a; i++){
    fact[i] = (fact[i-1] * i) % mod;

    long long ans = 1;
    long long n = mod-2;
    long long x = fact[i];
    while(n){
      if(n & 1){
        ans = (ans * x) % mod;
      }
      x = (x * x) % mod;
      n>>=1;
    }
    inv[i] = ans % mod;
    // cout << fact[i] << " " << inv[i] << endl;
  }
  return ( fact[a] * (inv[b] * inv[a-b] % mod)) % mod;
}

// long long mo=1000000007;
// long long comb(long long N_, long long C_) {
// 	const int NUM_=400001;
// 	static long long fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
// 	if (fact[0]==0) {
// 		inv[1]=fact[0]=factr[0]=1;
// 		for (int i=2;i<=NUM_;++i){
//       inv[i] = inv[mo % i] * (mo - mo / i) % mo;
//     }
// 		for (int i=1;i<=NUM_;++i){
//       fact[i]=fact[i-1]*i%mo;
//       factr[i]=factr[i-1]*inv[i]%mo;
//     }
// 	}
// 	if(C_<0 || C_>N_) return 0;
// 	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
// }


int main(){
  long long mo = 1000000007;
  long long n, m, k;
  cin >> n >> m >> k;
  long long x = 0;
  long long y = 0;

  for(long long i = 1 ; i < n ; i++){
    long long d = (i * (n-i))%mo;
    x += d;
    x = x%mo;
  }
  for(long long i = 1 ; i < m ; i++){
    long long d = (i * (m-i))%mo;
    y += d;
    y = y%mo;
  }
  cout << ((x*m*m+y*n*n)%mo * comb(n*m-2, k-2)) %mo << endl;
  // cout << comb(18, 2) << endl;
}
