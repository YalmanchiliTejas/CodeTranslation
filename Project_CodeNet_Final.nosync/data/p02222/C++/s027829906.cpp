#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<int>> edge;
vector<int> dp;
vector<bool> ch;

string solve();
int dfs(int now);
int reroot(int now);

int main() {
  cin >> n;
  edge.resize(n);
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    edge[--a].push_back(--b);
    edge[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}

string solve() {
  string res;
  for(int i = 0; i < n; ++i) res += "1";
  dp.assign(n, 0);
  ch.assign(n, 0);
  ch[0] = 1;
  dfs(0);
  ch.assign(n, 0);
  ch[0] = 1;
  int num = reroot(0);
  if(num != -1)
    for(int j = 2; j <= num; ++j) res[j] = '0';
  return res;
}

int dfs(int now) {
  int res = 0;
  for(auto to : edge[now])
    if(!ch[to]) {
      ch[to] = 1;
      res = max(res, 1 + dfs(to));
    }
  return dp[now] = res;
}

int reroot(int now) {
  int res = -1, num = 0, bf = dp[now];
  dp[now] = 0;
  vector<int> child, pre, suf;
  for(auto to : edge[now]) {
    child.push_back(dp[to]);
    pre.push_back(dp[to]);
    suf.push_back(dp[to]);
  }
  num = child.size();
  for(int i = 1; i < num; ++i) {
    pre[i] = max(pre[i - 1], pre[i]);
    suf[num - i - 1] = max(suf[num - i], suf[num - i - 1]);
  }
  for(int i = 0; i < num; ++i)
    if(!ch[edge[now][i]]) {
      dp[now] = 0;
      ch[edge[now][i]] = 1;
      if(i != 0) dp[now] = max(dp[now], pre[i - 1] + 1);
      if(i != num - 1)
        dp[now] = max(dp[now], suf[i + 1] + 1);
      res = max(res, reroot(edge[now][i]));
    }
  if(num >= 3) {
    sort(child.begin(), child.end(), greater<int>());
    if(child[0] == child[2])
      res = max(res, child[0] + child[2]);
    else
      res = max(res, child[0] + child[2] + 1);
  }
  dp[now] = bf;
  return res;
}
