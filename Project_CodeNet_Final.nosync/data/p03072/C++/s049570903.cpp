#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N)
  cin >> H[i];
  int ans = 0;
  REP(i, N)
  {
    bool ok = true;
    for (int j = 0; j < i; j++)
    {
      if (H[j] > H[i])
        ok = false;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}