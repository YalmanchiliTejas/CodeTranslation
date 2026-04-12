#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  std::vector<std::pair<int, int>> sp;
  while (true) {
    int p, s;
    scanf("%d,%d", &p, &s);
    if (p == 0 && s == 0)
      break;

    sp.emplace_back(-s, p);
  }

  std::sort(sp.begin(), sp.end());

  while (true) {
    int s;
    if (scanf("%d", &s) == EOF)
      return 0;

    int res=0, last=100;
    for (size_t i=0; i<sp.size(); ++i) {
      if (-sp[i].first < last)
        ++res;

      last = -sp[i].first;
      if (sp[i].second == s) {
        printf("%d\n", res);
        break;
      }
    }
  }
}

