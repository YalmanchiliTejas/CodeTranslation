#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define repr(i, m, n) for (int i = m; i >= n; i--)
#define db(x) cout << #x << "=" << x << endl;
template <class T>
bool maxi(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool mini(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
#define INF2 1000000000000000037
#define INF 1000000007
#define PI (acos(-1))
#define MOD 998244353
#define EPS 1e(-9);
using namespace std;
typedef long long ll;
//--GLOBAL---------------------------------
const int MAX = 10000010;
ll fac[MAX], finv[MAX], inv[MAX];
void cinit() { // O(nlogn)
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  reps(i, 2, MAX){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
ll c(int n, int k){ // 二項係数計算
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll modpow(ll a, ll n, ll mod=MOD){ // a^n % MOD の計算
  ll res = 1;
  while (n > 0){
      if(n & 1) res = res * a % mod;
      a = a * a  % mod;
      n >>= 1;
  }
  return res;
}

//--MAIN-----------------------------------
void Main() {

    ll N; cin>>N;
    cinit();

    ll res=modpow(3LL,N);

    ll hu=1;

    for(ll i=N;i>N/2;i--){
        res-=2*hu*c(N,i);

        res=res+(2LL*MOD*MOD);
        res%=MOD;
        hu*=2;
        hu%=MOD;
    }

    cout<< res<<"\n";


}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
