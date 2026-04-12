#include <stdio.h>
int main(void)
{
  int n;
  scanf("%d",&n);
  
  int m=800*n;
  int l=n/15;
  printf("%d",m-200*(l));
  
}