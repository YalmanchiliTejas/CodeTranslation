#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) {return a = min(a, b);}
template <typename T> T &chmax(T &a, const T &b) {return a = max(a, b);}

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

const int mod = 1e9+7;

struct Mod{
  int n;
  Mod() : n(0) {;}
  Mod(int m) : n(m){
    if(n>=mod) n%=mod;
    else if (n<0) n = (n%mod+mod)%mod;
  }
  operator int() {return n;}
};

Mod operator+=(Mod &a, Mod b) { a.n += b.n; if(a.n>=mod) a.n-=mod; return a; }
Mod operator-=(Mod &a, Mod b) { a.n -= b.n; if(a.n<0) a.n += mod; return a; }
Mod operator*=(Mod &a, Mod b) { a.n = ((long long)a.n * b.n) % mod; return a; }
Mod operator+(Mod a, Mod b) { return a+=b; }
Mod operator-(Mod a, Mod b) { return a-=b; }
Mod operator*(Mod a, Mod b) { return a*=b; }
Mod operator^(Mod a, int n) {
  if (n==0) return Mod(1);
  Mod res = (a*a) ^ (n/2);
  if (n%2) res = res * a;
  return res;
}
ll inv(ll a, ll p){
  return (a==1 ? 1 : (1-p*inv(p%a, a)) / a + p);
}
Mod operator/(Mod a, Mod b) { return a * Mod(inv(b.n, mod)); }
Mod fact[200005], factinv[200005];

void init(){
  fact[0] = Mod(1); factinv[0] = Mod(1);
  REP(i, 200004){
    fact[i+1] = fact[i] * Mod(i+1);
    factinv[i+1] = factinv[i] / Mod(i+1);
  }
}
Mod comb(int a, int b) {
  return fact[a] * factinv[b] * factinv[a-b];
}

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  init();
  Mod res(0);
  Mod N(n);
  Mod M(m);
  REP(i, n){
    Mod diff(n-i-1);
    res += comb(n*m-2, k-2) * diff * M * M * (N - diff);
  }
  REP(i, m){
    Mod diff(m-i-1);
    res += comb(n*m-2, k-2) * diff * N * N * (M - diff);
  }
  cout << int(res) << endl;
  return 0;
}