#include <cstdio>
#include <algorithm>
using namespace std;

struct C {
  int s;
  int i;
  
  static bool greater(const C &l, const C &r) {
    return l.s > r.s;
  }
};

int main() {
  char country[10][21];
  C obj[10];
  int n, a, b, c;
  bool flg = false;
  while (1) {
    scanf("%d\n", &n);
    if (!n) break;
    for (int i=0; i<n; i++) {
      scanf("%s %d %d %d\n", country[i], &a, &b, &c);
      obj[i].s = 3*a+c;
      obj[i].i = i;
    }
    stable_sort(obj, obj+n, C::greater);
    if (!flg) {
      flg = true;
    } else {
      printf("\n");
    }
    for (int i=0; i<n; i++) {
      printf("%s,%d\n", country[obj[i].i], obj[i].s);
    }
  }
  return 0;
}