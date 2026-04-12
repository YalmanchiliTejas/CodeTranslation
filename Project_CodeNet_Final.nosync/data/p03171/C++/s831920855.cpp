#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 3e3 + 9, M = 5e2 + 9, OO = 1e9 + 7, MOD = 1e9 + 9;
const ll inf = 1e18;

int arr[N];
ll mem[N][N][2];

ll solve(int start, int end, int player) {
  if(start > end)
    return 0;
  ll& ret = mem[start][end][player];
  if(~ret)
    return ret;
  if(player)
    ret = inf;
  else
    ret = -inf;
  ll c1 = solve(start + 1, end, player ^ 1) + arr[start] * (player ? -1ll : 1ll);
  ll c2 = solve(start, end - 1, player ^ 1) + arr[end] * (player ? -1ll : 1ll);
  if(player)
    return ret = min(c1, c2);
  else
    return ret = max(c1, c2);
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  memset(mem, -1, sizeof mem);
  cout << solve(0, n-1, 0);
  return 0;
}
