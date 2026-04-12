#include <iostream>
#include <vector>
 
using namespace std;
 
//combinationを作る前処理
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}
 
const int MAX = 210000;
const int MOD = 1000000007;
 
 
 
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
 
long long com(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}
 
int main() {
    int n, m, k;
    COMinit();
    cin >> n >> m >> k;
  
    long long res = 0;
  
  for(int d =1;d<n;d++){
   res += ((((com(n*m-2,k-2)*(n - d) % MOD)* m% MOD) * m % MOD) * d % MOD) % MOD;
  }
  for(int d =1;d<m;d++){
   res += ((((com(n*m-2,k-2)*(m - d) % MOD)* n% MOD) * n % MOD) * d % MOD) % MOD;
  }
  
  
   
    cout << res%1000000007 << endl;
}          
