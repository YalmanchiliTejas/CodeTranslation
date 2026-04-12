#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
int n;
vector<int> a;
vector<vector<bool> > used(3001, vector<bool>(3001, false));
vector<vector<long long> > memo(3001, vector<long long>(3001));
long long dfs(int left, int right) {
  if (used[left][right]) return memo[left][right];
  used[left][right] = true;
  if (left + right == n) memo[left][right] = 0;
  else if ((left + right) % 2 == 0) memo[left][right] = max(dfs(left + 1, right) + a[left], dfs(left, right + 1) + a[n - right -1]); // taro
  else memo[left][right] = min(dfs(left + 1, right) - a[left], dfs(left, right + 1) - a[n - right - 1]);
  return memo[left][right];
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  cin >> n;
  REP(i, n) {
    int aa; cin >> aa;
    a.push_back(aa);
  }
  cout << dfs(0, 0) << '\n';
  return 0;
}
