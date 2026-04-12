#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAX = 4000010;

const ll MOD = 1e9 + 7;

long long fac[MAX], finv[MAX], inv[MAX];
 
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
 
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
 
 
 



int main(){
ll N,M,K; cin >> N >> M >> K;
  COMinit();
  
  ll sum = 0;
  
  for(ll i = 0; i < N ; i++){
    for(ll j = 0; j < M; j++){
      if( i == 0 || j == 0){ sum += ( N - i)*( M - j) * ( i + j ) ; sum = sum % MOD;}
      else{ sum += 2 * ( N - i) * ( M - j) * ( i + j) ; sum = sum % MOD;} 
    }}
  
  sum *= COM( N * M - 2, K - 2) ; sum = sum % MOD;
  cout << sum << endl; return 0;}
  
  