#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;

int n, m;
ll ans = 0;
vector<bool> load;
vector<vector<int>> vec;

void dfs(int now, int cnt) {
  load[now] = true;
  cnt++;
  
  if (cnt == n) {
    ans++;
  }
  
  for (auto itr = vec[now].begin(); itr != vec[now].end(); itr++) {
    if (load[*itr]) {
      continue;
    }
    dfs(*itr, cnt);
  }
  load[now] = false;
  cnt--;
}

int main()
{
  cin >> n >> m;
  load.resize(n, false);
  vec.resize(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    vec[from].push_back(to);
    vec[to].push_back(from);
  }
  
  dfs(0, 0);
  
  cout << ans << endl;
  return 0;
}
