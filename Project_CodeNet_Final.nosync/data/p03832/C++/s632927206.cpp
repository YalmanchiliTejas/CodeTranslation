#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

const int mod = 1000000007;

struct Mod {
  int n;
  Mod () : n(0) {;}
  Mod (int m) : n(m) {
    if (n >= mod) n %= mod;
    else if (n < 0) n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};

bool operator==(Mod a, Mod b) { return a.n == b.n; }
Mod operator+=(Mod &a, Mod b) { a.n += b.n; if (a.n >= mod) a.n -= mod; return a; }
Mod operator-=(Mod &a, Mod b) { a.n -= b.n; if (a.n < 0) a.n += mod; return a; }
Mod operator*=(Mod &a, Mod b) { a.n = ((long long)a.n * b.n) % mod; return a; }
Mod operator+(Mod a, Mod b) { return a += b; }
Mod operator-(Mod a, Mod b) { return a -= b; }
Mod operator*(Mod a, Mod b) { return a *= b; }
Mod operator^(Mod a, int n) {
  if (n == 0) return Mod(1);
  Mod res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}

ll inv(ll a, ll p) {
  return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
Mod operator/(Mod a, Mod b) { return a * Mod(inv(b, mod)); }

#define MAX_N 1001

Mod fact[MAX_N], factinv[MAX_N];
void init() {
  fact[0] = Mod(1); factinv[0] = 1;
  REP(i,MAX_N-1) {
    fact[i+1] = fact[i] * Mod(i+1);
    factinv[i+1] = factinv[i] / Mod(i+1);
  }
}
Mod comb(int a, int b) {
  return fact[a] * factinv[b] * factinv[a-b];
}

Mod memo[MAX_N][MAX_N];
int N, A, B, C, D;

Mod dp(int i, int j) {
  if(i < 0 || j < 0) return Mod(0);
  if(memo[i][j].n != 0) return memo[i][j];
  if(i < A) {
    if(j > 0) return memo[i][j] = Mod(0);
    else return memo[i][j] = Mod(1);
  }
  if(j == 0) return memo[i][j] = Mod(1);

  Mod res = dp(i - 1, j);
  for(int k = C; k <= D; ++k) {
    if(j - i * k < 0) break;
    Mod tmp = dp(i - 1, j - i * k) * fact[N - j + i * k] * factinv[N - j] * factinv[k];
    REP(l,k) tmp *= factinv[i];
    res += tmp;
  }

  return memo[i][j] = res;
}

int main(){
  cin >> N >> A >> B >> C >> D;

  init();
  REP(i,MAX_N)REP(j,MAX_N) memo[i][j] = Mod(0);

  cout << dp(B, N).n << endl;
  return 0;
}

