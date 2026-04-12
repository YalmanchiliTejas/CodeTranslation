#include<cstdio>
using namespace std;
int main(void) {
  int n;
  scanf("%d", &n);
  n = n * 800 - 200 * (n/15);
  printf("%d\n", n);
  return 0;
}