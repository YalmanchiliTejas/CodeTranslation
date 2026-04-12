#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,M,K;

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
  if (n < k){ return 0;}
  if (n < 0 || k < 0) {return 0;}
     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
     }
 







ll number(ll a, ll b){
  if( a == 0|| b == 0){ return (( N - a ) * ( M - b)) % MOD;}
  else{
    return (  2 * ( N - a) * ( M - b)) % MOD;}}


int main(){
  cin >> N >> M >> K;
  
  COMinit();
  
  ll ans = 0;
  
  for(ll X = 0; X < N; X++){
    for(ll Y = 0; Y < M; Y++){
      
      ans += ( X + Y) * number(X ,Y) * COM( N * M  -2 , K - 2);
      ans %= MOD;}}
    
    cout << ans << endl; return 0;}