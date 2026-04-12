#include <iostream>
using namespace std;

int main()
{
  int x = 0;
  int y = 0;
  int n = 0;
  scanf("%d",&n);
  x = 800*n;
  y = n/15 * 200;
  printf("%d\n",x-y);
  return 0;
}
