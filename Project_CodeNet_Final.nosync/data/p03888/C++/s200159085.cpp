#include <cstdio>
using namespace std;

int main() {
  double r1, r2, r3;
  scanf("%lf%lf%lf", &r1, &r2, &r3);
  printf("%.12f\n", r1*r2/(r1+r2));
  return 0;
}