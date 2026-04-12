#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int n, m;
int a[100], b[100];
bool graph[10][10];
int ans = 0;

void dfs(int x, int mask) {
  bitset<10> h(mask);
  cerr << x << " " << h << endl;
  if (mask == (1<<n)-1) {
    ans++;
    return;
  }

  rep(i, n) {
    if (graph[x][i] == false) continue;
    if (mask & (1<<i)) continue;

    dfs(i, mask | (1<<i));
  }
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  cin >> n >> m;
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  dfs(0, 1);

  cout << ans << endl;
}