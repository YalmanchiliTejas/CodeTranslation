#include <cstdio>

using namespace std;

int x;

int main()
{
  scanf("%d", &x);
  if (x == 3 || x == 5 || x == 7)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}