#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<vector<int64_t>, vector<int64_t>> MakeVec(
  unordered_map<int64_t, int64_t>& nodes, int64_t st) {
  vector<int64_t> vec;
  vec.push_back(st);
  vector<int64_t> sums(2, 0);
  sums[1] = st;
  int64_t cur = nodes[st];
  while (cur != st) {
    vec.push_back(cur);
    sums.push_back(sums.back() + cur);
    cur = nodes[cur];
  }
  return {vec, sums};
}

int main() {
  int64_t N, X, M;
  cin >> N >> X >> M;

  unordered_map<int64_t, int64_t> nodes;
  vector<int64_t> loop, sums;
  int64_t sum = X;
  int64_t pre = X;
  int64_t n = 1;
  for (; n < N; ++n) {
    int64_t cur = pre * pre % M;
    if (nodes.count(cur)) {
      if (cur != pre) nodes[pre] = cur;
      tie(loop, sums) = MakeVec(nodes, cur);
      break;
    }
    nodes[pre] = cur;
    pre = cur;
    sum += cur;
  }
  if (n == N) {
    cout << sum << endl;
  } else {
    int64_t rest = N - n;
    cout << sum + sums.back() * (rest / loop.size()) + sums[rest % loop.size()] << endl;
  }
  
  return 0;
}
