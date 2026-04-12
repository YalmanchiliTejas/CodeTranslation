#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  int temp;
  scanf("%d", &temp);
  if (temp >= 30)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }

  return 0;
}
