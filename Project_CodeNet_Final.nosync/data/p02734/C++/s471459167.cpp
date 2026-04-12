
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
#include <regex>
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
// if ( std::regex_match(S, std::regex("(dream|dreamer|erase|eraser)*")) ) std::cout << "YES" << std::endl;

#define rep(i,n)  for(int i = 0; i < (int)(n);    i++)
#define sz(x)     ((int)(x).size())
#define all(x)    (x).begin(),(x).end()

using ll = long long;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 998244353;
struct mint {
  typedef long long ll;
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  bool operator>(const mint a) const {
    mint res(*this);
    return res.x > a.x;
  }
  bool operator<(const mint a) const {
    mint res(*this);
    return res.x < a.x;
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
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

constexpr int premax = 200020; 
std::array<mint, premax> f, rf; 
bool mymodflag = false;
mint nCk (int n, int k) {
  if ( n == k ) return mint(1);
  if ( n < k  ) return mint(0);
  if ( !mymodflag ) {
    f[0] = 1; for(int i=1; i<premax; i++) f[i] = f[i-1]*i;
    rf[premax-1] = f[premax-1].pow(mod-2); for(int i=premax-2; i>=0; i--) rf[i] = rf[i+1]*(i+1);
    mymodflag = true;
  }
  return f[n]*rf[n-k]*rf[k];
}

mint nPk (int n, int k) {
  if ( n < k  ) return mint(0);
  if ( !mymodflag ) {
    f[0] = 1; for(int i=1; i<premax; i++) f[i] = f[i-1]*i;
    rf[premax-1] = f[premax-1].pow(mod-2); for(int i=premax-2; i>=0; i--) rf[i] = rf[i+1]*(i+1);
    mymodflag = true;
  }
  return f[n]*rf[n-k];
}

mint dp[5000][5000] = { {0} };

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N, S; std::cin >> N >> S;
  std::vector<int> A(N); rep(i,N) std::cin >> A[i];

  mint res = 0;
  dp[0][0] = 1;
  for(int i=0; i<N; i++) {
    for(int s=0; s<=S; s++) dp[i+1][s] += dp[i][s];
    if ( A[i] <= S ) dp[i+1][A[i]] += i+1;
    for(int s=1; s<=S; s++) if (A[i] + s <= S) dp[i+1][s+A[i]] += dp[i][s];
    if ( A[i] == S ) res += (i+1)*(N-i);
    for(int s=1; s<=S; s++) if (A[i] + s == S) res += dp[i][s] * (N - i);
  }
  std::cout << res.x << std::endl;
  return 0;
}

