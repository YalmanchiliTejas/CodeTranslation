#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000

int main()
{
  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;

  ll sum1 = a * x + b * y;

  ll sum2 = 0;
  if (x < y) {
    sum2 = c * x * 2 + (y - x) * b;
  } else {
    sum2 = c * y * 2 + (x - y) * a;
  }

  ll sum3 = max(x, y) * c * 2;

  cout << min (sum1, min(sum2, sum3)) << endl;
  return 0;
}
