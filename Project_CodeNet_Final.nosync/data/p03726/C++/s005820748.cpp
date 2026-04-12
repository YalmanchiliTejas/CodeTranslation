#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf 1000000007LL
#define mod 1000000007LL

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

int n;
vector<int> v[114514];

int dfs(int p, int o) {
  int all = 1;
  bool can = false;
  for(auto i : v[p]) {
    if(i != o) {
      int w = dfs(i, p);
      if(w % 2 == 1) {
        if(can) {
          cout << "First" << endl;
          exit(0);
        }
        can = true;
      }
      all += w;
    }
  }
  if((n - all) % 2 == 1 && can) {
    cout << "First" << endl;
    exit(0);
  }
  return all;
}

signed main() {
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0, -1);
  cout << "Second" << endl;
}
