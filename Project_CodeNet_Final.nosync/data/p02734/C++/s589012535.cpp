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

const ll MOD = 998244353;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

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

int main(){
  int N, S; cin >> N >> S;
  vector<int> A(N); rep(i, N) cin >> A[i];

  vector<mint> f(S + 1, 0);
  vector<mint> F(S + 1, 0);
  for (int a: A){
    F[0] += 1;
    vector<mint> next(S + 1, 0);
    rep(i, S + 1){
      next[i] += F[i];
      if (i + a <= S) next[i + a] += F[i];
    }
    swap(next, F);
    rep(i, S + 1){
      f[i] += F[i];
    }
  }
  cout << f[S].x << endl;
}
