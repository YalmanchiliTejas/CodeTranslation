#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define INF 1100000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define Decimal fixed << setpresicion(20)


typedef long long ll;
typedef pair<ll, ll> P;

ll N, X;
ll twopow[61];

void makepow()
{
  twopow[0] = 1;
  REP(i, 60) twopow[i + 1] = twopow[i] * 2;
}

ll rec(ll X, ll L)
{
  if (L == 0) return 1;
  if (X == 1) return 0;
  if (1 < X && X < twopow[L+1] - 1) return rec(X-1, L-1);
  if (X == twopow[L+1] - 1) return twopow[L];
  if (twopow[L+1] - 1 < X) return twopow[L] + rec(X - (twopow[L+1] - 1), L - 1);
}

int main()
{
  makepow();
  cin >> N >> X;
  cout << rec(X, N) << endl;
  return 0;
}
