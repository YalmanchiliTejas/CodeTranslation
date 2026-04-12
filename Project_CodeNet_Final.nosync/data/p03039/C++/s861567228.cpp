#include <iostream>
using namespace std;

#define MOD 1000000007LL

typedef long long ll;

ll extgcd(ll a, ll b, ll& x, ll& y){
  ll d = a;
  if(b != 0){
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  else{
    x = 1;
    y = 0;
  }
  return d;
}

ll mod_inverse(ll a, ll m){
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

ll fact[200002];

ll mod_fact(ll n, ll p, ll &e){
  e = 0;
  if(n == 0) return 1;
 
  ll res = mod_fact(n / p, p, e);
  e += n / p;
 
  if(n / p % 2 != 0) return res * (p - fact[(int)(n % p)]) % p;
  return res * fact[(int)(n % p)] % p;
}

ll mod_comb(ll n, ll k, ll p){
  if(n < 0 || k < 0 || n < k) return 0;
  ll e1, e2, e3;
  ll a1 = mod_fact(n, p, e1);
  ll a2 = mod_fact(k, p, e2);
  ll a3 = mod_fact(n - k, p, e3);
  if(e1 > e2 + e3) return 0;
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  
  ll H, W, K;

  while (cin >> H >> W >> K) {
    ll a = 0;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        // y方向の計算
        // iより下
        ll distY = H - i;
        ll distX = W - j;
        a += distY * (distY - 1) / 2 * distX;
        a %= MOD;

        // iより上
        a += i * (i + 1) / 2 * (distX - 1);
        a %= MOD;

        // x方向の計算
        a += distX * (distX - 1) / 2 * H;
        a %= MOD;
      }
    }
    
    ll b = mod_comb(H * W - 2, K - 2, MOD);

    cout << (a * b) % MOD << endl;
  }
}
