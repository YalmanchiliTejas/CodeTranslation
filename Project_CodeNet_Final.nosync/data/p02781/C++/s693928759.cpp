#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "


string s;
int k;
ll pw(ll x)
{
  ll ret = 1;
  for (int i = 0; i < x; ++i) ret *= 9;
  return ret;
}
ll cb(ll n, ll b)
{
  if (b < 0 || n < 0 || n < b) return 0;
  ll ret = 1;
  for (int i = 1; i <= b; ++i)
    ret = ret * (n+1-i) / i;
  return ret * pw(b);
}

ll dfs(int cur, int left)
{
  if (left == 0) return 1;
  if (cur == s.length()) return 0;
  if (s[cur] == '0') return dfs(cur+1, left);
  int digit = s[cur]-'0';
  return cb(s.length()-cur-1, left) + (digit-1) * cb(s.length()-cur-1, left-1) + dfs(cur+1, left-1);
}
ll solve()
{
  return dfs(0, k);
}
int main()
{
  //  ios::sync_with_stdio(false);
  //  cin.tie(0);
  while (cin >> s >> k)
    {
      printf("%lld\n", solve());
    }
}
