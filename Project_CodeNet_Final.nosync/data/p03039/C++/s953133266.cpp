#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
#include <bitset>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

const int MAX = 510000; //nCrのr
//const ll INF = (ll)1e18 + 1;

#include <cassert>
long long fac[MAX], finv[MAX], inv[MAX], facn[MAX];
class mint {
public:
    long long x;
    mint(long long x=0) : x((x%MOD+MOD)%MOD) {}
    //mint operator-() const{ return mint(-x);}
    mint operator-() const {
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

};

template<class T>
struct combination {
    vector<T> fact_, ifact_;
    combination(long long n):fact_(n+1),ifact_(n+1) {
      assert(n < MOD);
      fact_[0] = 1;
      for (int i = 1; i <= n; ++i) fact_[i] = fact_[i-1]*i;
      ifact_[n] = fact_[n].inv();
      for (int i = n; i >= 1; --i) ifact_[i-1] = ifact_[i]*i;
    }
    T com(long long n, long long k) {
      if (k < 0 || k > n) return 0;
      return fact_[n]*ifact_[k]*ifact_[n-k];
    }
    T fact(ll n){
      if (n < 0) return 0;
      return fact_[n];
    }
};

int main(){
  ll N, M, K; cin >> N >> M >> K;
  combination<mint> C(1000000);
  mint sum = 0;
  for (int i = 0; i <= N - 1; ++i){
    for (int j = 0; j <= M - 1; ++j){
      mint tmp = mint(N - i) * mint(M - j) * (i + j);
      if (i != 0 && j != 0) tmp *= 2;
      sum += tmp;
    }
  }
  sum *= C.com(N * M - 2, K - 2);
  cout << sum.x << endl;
}
