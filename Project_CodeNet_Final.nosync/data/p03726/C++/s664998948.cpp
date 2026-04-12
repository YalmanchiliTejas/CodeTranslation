#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

vector<int> edges[100005];
int depth[100005];
bool used[100005];
void dfs(int curr, int par=0) {
  for(int out: edges[curr]) {
    if(out == par) continue;
    depth[out] = depth[curr]+1;
    dfs(out, curr);
  }
}
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(1);
  vector<pii> v;
  for(int i = 1; i <= n; i++) {
    v.emplace_back(depth[i], i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for(pii out: v) {
    int curr = out.second;
    if(used[curr]) continue;
    int found = -1;
    for(int out: edges[curr]) {
      if(depth[out] < depth[curr] && !used[out]) {
        found = out;
      }
    }
    if(found == -1) {
      cout << "First\n";
      return;
    }
    used[found] = true;
  }
  cout << "Second\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << "\n";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
