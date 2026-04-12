#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <utility>

#define MAX_N (100000)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, as[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }

  // solve greedy
  set<pair<int, int>> ps;
  ps.insert(make_pair(as[0], 0));
  for (int i = 1; i < N; i++) {
    // for (pair<int, int> p : ps) {
    //   printf("(%d, %d) ", p.first, p.second);
    // }
    // printf("\n");
    // printf("%d\n", (--ps.end())->first);
    // get maximum less than a
    const int a = as[i];
    auto it = ps.lower_bound(make_pair(a, 0));
    if (it != ps.begin()) {
      --it;
      if (it->first < a) {
        // use same color
        ps.erase(it);
      }
    }
    ps.insert(make_pair(a, i));
  }
  // for (pair<int, int> p : ps) {
  //   printf("(%d, %d) ", p.first, p.second);
  // }
  // printf("\n");
  // printf("%d\n", (--ps.end())->first);
  printf("%d\n", (int)ps.size());

  return 0;
}
