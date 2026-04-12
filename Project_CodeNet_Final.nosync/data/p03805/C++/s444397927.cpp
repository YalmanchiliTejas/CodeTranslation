#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)

using namespace std;

long N, M;
unordered_map<long, unordered_set<long>> neibor;
long result = 0;

void solve(unordered_set<long> visited, long current) {
  if (visited.size() == N) {
    result ++;
    return;
  }
  for (long n: neibor[current]) {
    if (visited.count(n) > 0) continue;
    unordered_set<long> tmp = visited;
    tmp.insert(n);
    solve(tmp, n);
  }
}

int main(void) {
  cin >> N >> M;
  for (long i = 0; i < M; i++) {
    long a, b;
    cin >> a >> b;
    neibor[a].insert(b);
    neibor[b].insert(a);
  }
  unordered_set<long> visited;
  visited.insert(1);
  solve(visited, 1);
  cout << result << endl;
  return 0;
}
