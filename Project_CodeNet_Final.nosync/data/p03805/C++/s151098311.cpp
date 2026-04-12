#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m;
  cin >> n >> m;
  int d[n][n] = {}; // important!!
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d[a][b] = 1;
    d[b][a] = 1;
  }

  vector<int> v(n);
  rep(i,n) v[i] = i;
  int ans = 0;

  do {
    bool b = true;
    if (v[0] != 0) break;
    for(int i = 0; i < n - 1; i++) {
      if (!d[v[i]][v[i+1]]) {
        b = false;
      }
    }
    if(b) ans++;
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}