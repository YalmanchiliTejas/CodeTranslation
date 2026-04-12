#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL 9223372036854775
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 1000000007
#define MOD9 998244353
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

using II = pair<int, int>;

int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int extgcd(int a, int b, int &x, int &y) { int g = a; x = 1; y = 0; if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x; return g; }

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

struct ModInt {
  static void setMod(int m) {
    mod = m;
  }

  ModInt(int val = 0) : val(val%mod) {}

  inline const ModInt operator + (const ModInt& rhs) const {
    return ModInt((this->val + rhs.val) % mod);
  }

  inline const ModInt operator - (const ModInt& rhs) const {
    return ModInt((this->val + mod - rhs.val) % mod);
  }

  inline const ModInt operator * (const ModInt& rhs) const {
    return ModInt((this->val * rhs.val) % mod);
  }

  inline ModInt& operator += (const ModInt& rhs) {
    this->val = (this->val + rhs.val) % mod;
    return *this;
  }

  inline ModInt& operator -= (const ModInt& rhs) {
    this->val = (this->val + mod - rhs.val) % mod;
    return *this;
  }

  inline ModInt& operator *= (const ModInt& rhs) {
    this->val = (this->val * rhs.val) % mod;
    return *this;
  }

  int val;
  static int mod;
};
int ModInt::mod = MOD9;

const int MAX_N = 3005;
const int MAX_S = 3005;
int N, S;
int A[MAX_N];

ModInt dp[MAX_N][MAX_S][3];

signed main()
{
  cin >> N >> S;
  REP(n,N) {
    cin >> A[n];
  }

  dp[0][0][0] = 1;
  REP(n,N) {
    REP(s,S+1) {
      dp[n+1][s][0] += dp[n][s][0];
      dp[n+1][s][1] += dp[n][s][0] + dp[n][s][1];
      dp[n+1][s][2] += dp[n][s][0] + dp[n][s][1] + dp[n][s][2];
      if (s + A[n] <= S) {
        dp[n+1][s+A[n]][1] += dp[n][s][0] + dp[n][s][1];
        dp[n+1][s+A[n]][2] += dp[n][s][0] + dp[n][s][1];
      }
    }
  }

  cout << dp[N][S][2].val << endl;

  return 0;
}

