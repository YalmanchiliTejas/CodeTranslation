#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define trav(a,x) for(auto& a: x)
#define all(x) begin(x),end(x)
#define sz(x) (int)size(x)
#define PB push_back
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using vi = vector<int>;

struct edge{int to;};
using graph = vector<vector<edge>>;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  ll n, x, m;
  cin >> n >> x >> m;

  vi vis(m + 1);
  
  int stage = 0;
  ll init = 0;
  int init_len = 0;
  vector<ll> loop;
  auto curr = x;
  rep(i, 0, n) {
    // cout << "At step : " << i << " with " << curr << endl;
    if (stage == 0 and vis[curr] != 0) {
      stage = 1;
    } else if (stage == 1 and vis[curr] > 1) {
      break;
    }
    // cout << "At stage " << stage << endl;

    vis[curr]++;
    if (stage == 0) init += curr, init_len++;
    else if (stage == 1) loop.PB(curr);

    curr = (curr * curr) % m;
  }
  auto rem = n - init_len;
  auto num_loops = sz(loop) ? rem / sz(loop) : 0;
  auto extra = sz(loop) ? rem % sz(loop) : 0;

  // cout << "Rem: " << rem << " Loops: " << num_loops << " extra: " << extra << endl;

  auto loop_total = accumulate(all(loop), 0LL);

  ll res = init + num_loops * loop_total + accumulate(begin(loop), begin(loop) + extra, 0LL);
  cout << res << '\n';
}
