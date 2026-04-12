#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=1000000007;
ll MOD=998244353;
int inf=1000001000;
ll INF=10000000000000000;

void Add(int &a, int b) {
  a += b;
  while (a >= MOD) a -= MOD;
  while (a < 0) a += MOD;
}
 
void Mul(int &a, int b) {
  a = 1LL * a * b % MOD;
}
 
int Pow(int b, int e) {
  if (e < 0) e += MOD - 1;
  int ret = 1;
  while (e) {
    if (e & 1) ret = 1LL * ret * b % MOD;
    b = 1LL * b * b % MOD;
    e >>= 1;
  }
  return ret;
}
 
namespace Math {
  const int NMAX = (int)1e7;
  int pow2[1 + NMAX];
  int fact[1 + NMAX], tcaf[1 + NMAX];
  void Precalc() {
    fact[0] = pow2[0] = 1;
    for (int i = 1; i <= NMAX; ++i) {
      pow2[i] = pow2[i - 1];
      Add(pow2[i], pow2[i]);
 
      fact[i] = fact[i - 1];
      Mul(fact[i], i);
    }
    tcaf[NMAX] = Pow(fact[NMAX], -1);
    for (int i = NMAX - 1; i >= 0; --i) {
      tcaf[i] = tcaf[i + 1];
      Mul(tcaf[i], i + 1);
      assert(1LL * fact[i] * tcaf[i] % MOD == 1);
    }
  }
  int Choose(int n, int k) {
    if (k > n || n < 0) return 0;
    return 1LL * fact[n] * tcaf[n - k] % MOD * tcaf[k] % MOD;
  }
};

int main(){
    Math::Precalc();
    ll n;
    cin >> n;
    ll ans=Pow(3,n);
    rep(i,n/2){
        ans=(ans+2*MOD-(2LL*Pow(2,i)*Math::Choose(n,i)%MOD))%MOD;
    }
    cout << ans << endl;
}
