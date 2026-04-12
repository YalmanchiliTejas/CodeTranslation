#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int A,B,C,X,Y,kingaku;
  scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
  if (A + B < 2*C) kingaku = A*X + B*Y;
  else {
    int tmp;
    kingaku = C * 2 * min(X,Y);
    if (min(X,Y) == X) {
      tmp = min(B,2*C)*(Y-X);
      kingaku += tmp;
    } else {
      tmp = min(A,2*C)*(X-Y);
      kingaku += tmp;
    }
  }
  printf("%d\n",kingaku);
  return 0;
}
