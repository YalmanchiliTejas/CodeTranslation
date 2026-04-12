#include <cstdio>
using namespace std;

int main ()
{
  int X, Y, Z;
  int r, s;

  scanf("%d", &X);
  scanf("%d", &Y);
  scanf("%d", &Z);

  s = X / (Y + Z);
  r = X % (Y + Z);
  if (r < Z) {
    printf("%d\n", s-1);
  } else {
    printf("%d\n", s);
  }
  return 0;
}