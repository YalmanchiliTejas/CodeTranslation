#include <cstdio>
#include <algorithm>
using namespace std;

struct D {
  int n;
  int s;
  int r;
  D() {};

  D(const D &obj) {
    this->n = obj.n;
    this->s = obj.s;
    this->r = obj.r;
  }

  D &operator=(const D &obj) {
    this->n = obj.n;
    this->s = obj.s;
    this->r = obj.r;
  }
};

bool greater_s(const D &l, const D &r) {
  return (l.s > r.s);
}

bool less_n(const D &l, const D &r) {
  return (l.n < r.n);
}

int main() {
  D x[100];
  D tmp;
  D *p;
  int a, i, cur_s, cur_r;
  i = 0;
  while (1) {
    scanf("%d,%d", &tmp.n, &tmp.s);
    if (!tmp.n && !tmp.s) break;
    x[i] = tmp;
    ++i;
  }
  sort(x, x+i, greater_s);
  cur_s = x[0].s;
  cur_r = 1;
  for (int j=0; j<i; j++) {
    if (x[j].s == cur_s) {
      x[j].r = cur_r;
    } else {
      cur_s = x[j].s;
      x[j].r = ++cur_r;
    }
  }
  sort(x, x+i, less_n);
  while (scanf("%d", &tmp.n)==1) {
    p = lower_bound(x, x+i, tmp, less_n);
    printf("%d\n", p->r);
  }

  return 0;
}