#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> Pair;

vector<Pair> ps;
map<int, int> rank_table;

int main() {
  while (1) {
    int a, b;
    scanf("%d,%d", &a, &b);
    if (a == 0 && b == 0) break;

    ps.push_back(Pair(b, a));
  }
  sort(ps.begin(), ps.end(), greater<Pair>());

  int cur_rank = 0;
  int prev_score = -1;
  for (int i=0; i<ps.size(); i++) {
    if (ps[i].first != prev_score) {
      ++cur_rank;
    }

    rank_table[ps[i].second] = cur_rank;
    prev_score = ps[i].first;
  }

  while (1) {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    printf("%d\n", rank_table[q]);
  }
}