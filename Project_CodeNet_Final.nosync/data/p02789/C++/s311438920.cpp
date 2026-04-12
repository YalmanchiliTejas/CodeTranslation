#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
constexpr int64_t INF = 1000000000;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N, M;
  cin >> N >> M;
  if (N == M) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
