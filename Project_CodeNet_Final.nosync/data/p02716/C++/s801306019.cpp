#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N;
vector<int> A;
unordered_map<int, int64_t> memo[3];
int64_t dfs(int idx, int skip) {
  if(idx >= N) return 0;
  if (memo[skip].count(idx)) return memo[skip][idx];

  int64_t ret = dfs(idx + 2, skip) + A[idx];
  if(skip > 0) ret = max(ret, dfs(idx + 1, skip-1));
  memo[skip][idx] = ret;
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N;
  A.resize(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  int skip = (N % 2 == 0) ? 1 : 2;
  cout << dfs(0, skip) << endl;  
  return 0;
}
