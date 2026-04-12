#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
#define M 1000000007
typedef long long ll;

vector<ll> a;

int main()
{
  ll n, tempA, ans = 0, sum = 0;
  cin >> n;

  REP(i, n)
  {
    cin >> tempA;
    a.push_back(tempA);
  }

  REP(i, n - 1)
  {
    sum += a[i];
    sum %= M;
    ans += (a[i + 1] * sum);
    ans %= M;
  }
  cout << ans << endl;
}