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

int N;
string s;

bool check(bool sheep1, bool sheep2)
{
  vector<bool> sheep(N, false);
  sheep[0] = sheep1;
  sheep[1] = sheep2;
  for (int i = 2; i < N; i++)
  {
    if ((sheep[i - 1] && s[i - 1] == 'o') || (!sheep[i - 1] && s[i - 1] == 'x'))
      sheep[i] = sheep[i - 2];
    else if ((sheep[i - 1] && s[i - 1] == 'x') || (!sheep[i - 1] && s[i - 1] == 'o'))
      sheep[i] = !sheep[i - 2];
  }
  bool ok = false;
  bool check1, check2;
  if ((sheep[N - 1] && s[N - 1] == 'o') || (!sheep[N - 1] && s[N - 1] == 'x'))
    check1 = sheep[N - 2];
  else if ((sheep[N - 1] && s[N - 1] == 'x') || (!sheep[N - 1] && s[N - 1] == 'o'))
    check1 = !sheep[N - 2];
  if ((sheep[0] && s[0] == 'o') || (!sheep[0] && s[0] == 'x'))
    check2 = sheep[N - 1];
  else if ((sheep[0] && s[0] == 'x') || (!sheep[0] && s[0] == 'o'))
    check2 = !sheep[N - 1];
  if (check1 == sheep[0] && check2 == sheep[1])
    ok = true;
  if (ok)
  {
    REP(i, N)
    cout << (sheep[i] ? "S" : "W");
    cout << '\n';
    return true;
  }
  return false;
}

int main()
{
  cin >> N >> s;
  if (check(true, true))
    return 0;
  if (check(true, false))
    return 0;
  if (check(false, true))
    return 0;
  if (check(false, false))
    return 0;
  cout << -1 << endl;
  return 0;
}