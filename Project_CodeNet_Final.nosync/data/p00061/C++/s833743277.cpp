#include <cstdio>
#include <map>

using namespace std;

map<int, int> ps;
int os[31];

int main() {
  for (int id, x; scanf("%d,%d", &id, &x) == 2 && !(!id && !x);) {
    ps[id] = x;
    os[x]++;
  }
  for (int x = 30, o = 1; x >= 0; x--)
    if (os[x])
      os[x] = o++;
  for (int id; scanf("%d", &id) == 1;)
    printf("%d\n", os[ps[id]]);
  return 0;
}