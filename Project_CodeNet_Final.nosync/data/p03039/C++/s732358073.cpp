#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;


ll tableF[400010];
ll tableI[400010];

ll modfact(ll a,ll m){
   if(tableF[a] != -1){
      return tableF[a];
   }
   if(a == 1){
      tableF[a] = 1;
      return tableF[a];
   }
   ll res = 1;
   res = a * modfact(a-1,m);
   res %= m;
   tableF[a] = res;
   return res;
}

ll modpow(ll a,ll n,ll m){//modpow(a,n,m) := a ^ n (mod m)
  ll res = 1;
  while(n > 0){
    if(n & 1)res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a,ll p){//modinv(a,p) := pを法とするaの逆元(※pは素数でなければならない)
    ll res = modpow(a,p-2,p);
    return res;
}

ll modCON(ll n,ll r,ll m){
   if(n < 200010){
   ll res = 1;
   if(n < 0 || r < 0 || n < r){
      return 0;
   }
   res *= tableF[n];
   res %= m;
   res *= tableI[r];
   res %= m;
   res *= tableI[n-r];
   res %= m;
   return res;
   }else{
   ll res = 1;//tableを持ってないときよう
   for(int i = 1;i <= n;i++){
      res *= i;
      res %= m;
   }
   for(int i = 1;i <= r;i++){
      res *= modinv(i,m);
      res %= m;
   }
   for(int i = 1;i <= n-r;i++){
      res *= modinv(i,m);
      res %= m;
   }
   return res;
   }
}

void modfill(ll m){//忘れない　約200ms
   fill(tableF,tableF+400010,-1);
   fill(tableI,tableI+400010,-1);
   tableF[0] = 1;
   tableI[0] = 1;
   for(int i = 1;i < 200010;i++){
      tableF[i] = modfact(i,m);
      tableI[i] = modinv(tableF[i],m);
   }
}


int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    modfill(MOD);
    ll ans = 0;
    rep(i,N) {
        rep(j,M){
            ll A0 = ((M-j-1)*(M-j) / 2 + j * (j+1) / 2);
            ll D = N * A0 + ((N-i-1)*(N-i) / 2 + i * (i+1) / 2) * M;
            D %= MOD;
            D *= modCON(N*M-2,K-2,MOD);
            D %= MOD;
            ans += D;
            ans %= MOD;
        }
    }
    cout << (ans * modinv(2,MOD)) % MOD << endl;
}
