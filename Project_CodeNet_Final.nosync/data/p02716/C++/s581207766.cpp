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

const int MAX_N = 200005;
int N;
int A[MAX_N];
int sumA[2][MAX_N];
int preSumA[2][MAX_N];
int pre[MAX_N];

void preSolve()
{
  reverse(A, A+N);
  memset(preSumA, 0, sizeof(preSumA));
  REP(n,N) {
    preSumA[0][n+1] = preSumA[0][n];
    preSumA[1][n+1] = preSumA[1][n]; 
    preSumA[n%2][n+1] += A[n];
  }

  int l = 0, r = 0;
  for(int n = 0; n < N-1; n += 2) {
    int tmp1 = l+r+A[n+1];
    int tmp2 = preSumA[0][n] + A[n+1];
    int tmp3 = preSumA[0][n+2];
    if (tmp2 <= tmp1 && tmp3 <= tmp1) {
      r += A[n+1];
      pre[N-(n+2)] = tmp1;
    } else if(tmp1 <= tmp2 && tmp3 <= tmp2) {
      l = preSumA[0][n];
      r = A[n+1];
      pre[N-(n+2)] = tmp2;
    } else {
      l = preSumA[0][n+2];
      r = 0;
      pre[N-(n+2)] = tmp3;
    }
  }

  reverse(A, A+N);
}

int solve()
{
  memset(sumA, 0, sizeof(sumA));
  REP(n,N) {
    sumA[0][n+1] = sumA[0][n];
    sumA[1][n+1] = sumA[1][n]; 
    sumA[n%2][n+1] += A[n];
  }

  preSolve();
  if (N%2 == 0) {
    return pre[0];
  }

  int ans = -INF_LL;

  for(int n = 0; n < N; n += 2) {
    if (n+1 < N) {
      ans = max(ans, sumA[0][n] + pre[n+1]);
    }
    if (n+2 < N) {
      ans = max(ans, sumA[0][n] + sumA[0][N] - sumA[0][n+2]);
    }
  }
  ans = max(ans, sumA[0][N-1]);
  ans = max(ans, sumA[0][N] - sumA[0][2]);

  for(int n = 1; n < N; n += 2) {
    if (n+1 < N) {
      ans = max(ans, sumA[1][n] + sumA[0][N] - sumA[0][n]);
    }
  }
  ans = max(ans, sumA[1][N]);

  return ans;
}

signed main()
{
  cin >> N;
  REP(n,N) {
    cin >> A[n];
  }

  int ans = solve();

  cout << ans << endl;

  return 0;
}
