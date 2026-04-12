#include <bits/stdc++.h>
#define INF 1000000001
#define ll long long
using namespace std;



int main()
{
  ll N, M;
  cin >> N >> M;
  vector<vector<bool>> connect(N, vector<bool>(N, false));
  for (ll i = 0; i < M; ++i)
  {
    ll a, b;
    cin >> a >> b;
    connect.at(a - 1).at(b - 1) = true;
    connect.at(b - 1).at(a - 1) = true;
  }
  vector<ll> perm(N);
  for (ll i = 0; i < N; ++i)
  {
    perm.at(i) = i;
  }
  ll ans = 0;
  while (true)
  {
    if (perm.at(0) == 0)
    {
      ans += 1;
      for (ll i = 0; i < N - 1; ++i)
      {
        if (!connect.at(perm.at(i)).at(perm.at(i + 1)))
        {
          ans -= 1;
          break;
        }
      }
    }
    if (!next_permutation(perm.begin(), perm.end()))
    {
      break;
    }
  }
  cout << ans << endl;
}
