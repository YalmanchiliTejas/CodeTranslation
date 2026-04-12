#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int N, M, e[9][9]{}, a, b, p[8], ans{};
  cin >> N >> M;
  while (cin >> a >> b) {
    e[a][b] = e[b][a] = 1;
  }
  iota(begin(p), begin(p) + N, 1);
  do {
    ans += [&]() {
      for (int i = 0; i != N - 1; ++i)
        if (!e[p[i]][p[i + 1]]) return 0;
      return 1;
    }();
  } while (next_permutation(begin(p) + 1, begin(p) + N));
  cout << ans << endl;
}
