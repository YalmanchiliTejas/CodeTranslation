#include <cstdio>

int main()
{
  int N, y;
  
  scanf("%d", &N);
  
  y = N / 15;
  
  printf("%d", 800* N - 200 * y);
}