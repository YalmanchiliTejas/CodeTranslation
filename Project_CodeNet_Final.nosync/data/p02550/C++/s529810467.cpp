#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll n,m,x;
ll f(ll a) {
  return a*a % m;
}  

int main() {
  cin >> n >> x >> m;
  vector<int> id(m,-1);
  vector<int> seen;
  ll tot = 0;
  int len = 0;
  while (id[x] == -1)
  {
    seen.push_back(x);
    id[x] = len;
    len++;
    tot += x;
    x = f(x);
  }
  
  int c = len - id[x];
  ll s =  0;
  for (int i = id[x]; i < len; i++) s += seen[i];

  ll ans = 0;
  if (n <= len) {
    rep(i,n) ans += seen[i];
  } else {
    ans += tot;
    n -= len; 
    ans += s*(n/c);
    n %= c;
    rep(i,n) ans += seen[id[x]+i];
  }
  cout << ans << endl;
  return 0;
}