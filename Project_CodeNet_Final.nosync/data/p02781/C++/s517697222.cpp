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

const int MAX_N = 105;

string N;
int K;

int dp[MAX_N][5][2];

signed main()
{
  cin >> N;
  cin >> K;

  dp[0][0][0] = 1;

  REP(n,N.size()) {
    REP(k,K+1) {
      REP(flag,2) {
        // 0
        dp[n+1][k][flag | (N[n] != '0' ? 1 : 0)] += dp[n][k][flag];
        // 1以上9以下の数字を入れる
        if(flag) { // 自由
          dp[n+1][k+1][1] += dp[n][k][flag]*9;
        } else { // 制約あり
          if(N[n] > '0') {
            dp[n+1][k+1][1] += dp[n][k][flag] * (N[n]-'0'-1);
            dp[n+1][k+1][0] += dp[n][k][flag];
          }
        }
      }
    }
  }

  cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl;

  return 0;
}
