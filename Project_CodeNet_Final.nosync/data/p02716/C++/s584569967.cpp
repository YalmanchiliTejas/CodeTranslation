#ifdef ConanYu
#include "E:\yuzining\code\local.hpp"
#else
#pragma GCC optimize("-O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(...) do { } while(false)
void Main();
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie();
  Main();
  return 0;
}
#endif

int a[200005];

ll b[200005], c[200005];
map<tuple<int, int, int>, ll> mp;
ll dfs(int i, int n, int d) {
  if(d <= 0) return 0;
  if((n - i + 1) % 2 != 0 && d == (n - i + 1) / 2 + 1) {
    if(n & 1) return b[n] - b[i - 1];
    return c[n] - c[i - 1];
  }
  tuple<int, int, int> cur = {i, n, d};
  auto it = mp.find(cur);
  if(it != mp.end()) return it->second;
  ll c1 = dfs(i + 1, n, d);
  ll c2 = a[i] + dfs(i + 2, n, d - 1);
  mp[cur] = max(c1, c2);
  return max(c1, c2);
}

void Main() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    b[i] = b[i - 1];
    c[i] = c[i - 1];
    if(i & 1) b[i] += a[i];
    else c[i] += a[i];
  }
  cout << dfs(1, n, n / 2) << '\n';
}