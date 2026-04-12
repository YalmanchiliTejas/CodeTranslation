#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
bool used[10];
vector<int> g[10];

int dfs(int s, int num) {
  if(num == n-1)  {
    //cout << s << endl;
    return 1;
  }

  int ret = 0;
  for(int i=0;i<g[s].size();i++) {
    if(!used[g[s][i]]) {
      used[g[s][i]] = true;
      ret += dfs(g[s][i], num+1);
      used[g[s][i]] = false;
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);

  for(int i=0;i<m;i++) {
    int ai, bi;
    cin >> ai >> bi;
    ai--;bi--;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }

  ll ans = 0;
  memset(used, false, sizeof(used));
  used[0] = true;
  ans += dfs(0, 0);
  /*do {

  } while(next_permutation(v.begin(), v.end());
  */

  cout << ans << endl;

}
