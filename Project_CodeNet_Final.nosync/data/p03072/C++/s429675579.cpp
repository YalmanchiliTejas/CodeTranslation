#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> H(N);
  vector<bool> flg(N, true);
  REP(i, N)
  {
    cin >> H[i];
  }
  REP(i, N)
  {
    FOR(j, i + 1, N)
    {
      if (H[i] > H[j] && flg[j])
      {
        flg[j] = false;
      }
    }
  }
  cout << (int)count(flg.begin(), flg.end(), true) << "\n";
}