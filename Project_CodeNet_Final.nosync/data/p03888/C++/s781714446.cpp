#include <cstdio>
using namespace std;
int main() {
  int r1, r2;
  scanf("%d %d", &r1, &r2);
  printf("%.9f\n", 1.0 / (1.0 / r1 + 1.0 / r2));
  return 0;
}
