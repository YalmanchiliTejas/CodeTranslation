#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define RFOR(i, a, n) for (ll i = (ll)n - 1; i >= (ll)a; i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define bra(first, second) '(' << first << ',' << second << ')'
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
ll INF = 1001001001001001001;
long double EPS = 1e-9;
long double PI = 3.141592653589793238;
template <typename T>
void remove(std::vector<T> &vector, unsigned int index)
{
   vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

// MOD確認

ll modpow(ll a,ll n,ll m){//modpow(a,n,m) := a ^ n (mod m)
  ll res = 1;
  while(n > 0){
    if(n & 1)res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}


ll N;
ll A[200010];

int main(){
   cin >> N;
   ll ans = 0,sum = 0;
   rep(i,N){
      cin >> A[i];
      sum += A[i];
   }
   sum %= MOD;
   rep(i,N){
      ans += (sum - A[i]) * A[i];
      ans %= MOD;
      while(ans < 0) ans += MOD * (ll)100000000;
   }
   ans %= MOD;
   ans *= modpow(2LL,(ll)(MOD-2),MOD);
   cout << ans % MOD << endl;
}