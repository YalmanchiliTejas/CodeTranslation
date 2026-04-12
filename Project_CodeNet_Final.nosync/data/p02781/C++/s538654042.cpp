#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A,B,C,D,E,F,G,H,I,J,K,L,N,M,O,P,Q,R,S,T,U,V,W,x,y,z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

template <std::int_fast64_t Modulus> class modint {
  using u64 = std::int_fast64_t;
public:
  u64 a;
  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
typedef modint<MOD> m;
#pragma endregion

int dp[101][2][101] = {0};
vector<int> vec;
int main() {
  string s;
  cin >> s;
  cin >> K;
  for(auto a : s){
    vec.push_back(a-'0');
  }
  int l = s.size();
  dp[0][0][0] = 1;
  for(int i=0;i<l;i++){
    for(int smaller = 0;smaller < 2; smaller++){
      for(ll k=0;k<=K;k++){
        for(int x=0;x<=(smaller?9:vec[i]);x++){
          if(x != 0){
            dp[i + 1][smaller || x < vec[i]][k+1] += dp[i][smaller][k];
          }else{
            dp[i + 1][smaller || x < vec[i]][k] += dp[i][smaller][k];
          }
        }
      }
    }
  }
  cout << dp[l][0][K] + dp[l][1][K];
}

