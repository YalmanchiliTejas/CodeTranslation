#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n, m;
vector<char> g[10];

int solve(string s, char c) {
  s += c;

  if(s.length() == n) return 1;
  int p = (int)(s[s.length() - 1] - 48);
  int num = 0;
  rep(i, 0, g[p].size()) {
    bool f = 0;
    rep(j, 0, s.length()) if((char)(g[p][i] + 48) == s[j]) f = 1;
    if(f) continue;
    num += solve(s, (char)(g[p][i] + 48));
  }
  return num;
}

signed main() {
  cin >> n >> m;

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }

  cout << solve("", '1') << endl;
}
