#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const int MOD = 1000000007;
struct mint { int n; mint(int n_ = 0) : n(n_) {} };
mint operator-(mint a) { return -a.n + MOD * (a.n != 0); }
mint operator+(mint a, mint b) { int x = a.n + b.n; return x - (x >= MOD) * MOD; }
mint operator-(mint a, mint b) { int x = a.n - b.n; return x + (x < 0) * MOD; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
istream &operator>>(istream &i, mint &a) { return i >> a.n; }
ostream &operator<<(ostream &o, mint a) { return o << a.n; }

vector<mint> F_{1, 1}, R_{1, 1}, I_{0, 1};
void check_fact(int n) {
  for (int i = I_.size(); i <= n; i++) {
    I_.push_back(I_[MOD % i] * (MOD - MOD / i));
    F_.push_back(F_[i - 1] * i);
    R_.push_back(R_[i - 1] * I_[i]);
  }
}

mint I(int n) { check_fact(abs(n)); return n >= 0 ? I_[n] : -I_[n]; }
mint F(int n) { check_fact(n); return n < 0 ? 0 : F_[n]; }
mint R(int n) { check_fact(n); return n < 0 ? 0 : R_[n]; }
mint C(int n, int r) { return F(n) * R(n - r) * R(r); }
mint P(int n, int r) { return F(n) * R(n - r); }
mint H(int n, int r) { return n == 0 ? (r == 0) : C(n + r - 1, r); }

ll N, M, K;
int main(void){
    cin >> N >> M >> K;
    ll comb = C(int(N*M-2), int(K-2)).n;
    ll n1 = 0;
    for(ll i=0;i<N;i++){
        n1 += (i*(N-i)) % MOD;
        n1 %= MOD;
    }
    n1 *= (M*M)%MOD;
    n1 %= MOD;

    ll n2 = 0;
    for(ll i=0;i<M;i++){
        n2 += (i*(M-i)) % MOD;
        n2 %= MOD;
    }
    n2 *= (N*N)%MOD;
    n2 %= MOD;


    cout << (comb*(n1+n2))%MOD << endl;
    return 0;
}

