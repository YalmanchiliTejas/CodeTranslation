//C
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_N = 51;

int N, X;
int ssize[MAX_N];
int psize[MAX_N];

int ans = 0;

void calc(int level, int x)
{
  if(x <= 0) {
    return;
  }
  if(level == 0) {
    ans++;
    return;
  }
  if(x <= ssize[level-1]+1) {
    calc(level-1,x-1);
  } else if(x == ssize[level-1]+2) {
    ans += 1 + psize[level-1];
    return;
  } else {
    ans += 1 + psize[level-1];
    calc(level-1, x-2-ssize[level-1]);
  }
}

signed main()
{
  ssize[0] = psize[0] = 1;
  FOR(n,1,MAX_N) {
    ssize[n] = 3 + 2*ssize[n-1];
    psize[n] = 1 + 2*psize[n-1];
  }
  cin >> N >> X;

  calc(N, X);

  cout << ans << endl;

  return 0;
}