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
long long dfs(int left, int right, long long taro, long long jiro) {
  if (used[left][right]) return memo[left][right] + taro - jiro;
  if (left + right == n) return taro - jiro;
  used[left][right] = true;
  long long res;
  if ((left + right) % 2 == 0) { // taro
    res = max(dfs(left+1, right, taro+a[left], jiro), dfs(left, right+1, taro+a[n-right-1], jiro));
  } else {
    res = min(dfs(left+1, right, taro, jiro+a[left]), dfs(left, right+1, taro, jiro+a[n-right-1]));
  }
  memo[left][right] = res - taro + jiro;
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  cin >> n;
  REP(i, n) {
    int aa; cin >> aa;
    a.push_back(aa);
  }
  cout << dfs(0, 0, 0, 0) << '\n';
  return 0;
}
