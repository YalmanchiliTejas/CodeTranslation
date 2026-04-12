#include<stdio.h>

typedef long long int * pint;

int main()
{
  int n;
  scanf("%d", &n);
  
  long long int num[n], cursum[n], sum = 0;
  scanf("%lld", num);
  (*cursum) = (*num);
  for (pint p = num + 1, q = cursum + 1, pd = num + n; p < pd; p++, q++)
  {
  	scanf("%lld", p);
    (*q) = (*(q - 1)) + (*p);
    if ((*q) > (2 << 60)) (*q) %= 1000000007LL;
  }
  
  for (pint p = num + 1, q = cursum, pd = num + n; p < pd; p++, q++)
  {
    sum += (*p) * (*q);
    if (sum > (2 << 60)) sum %= 1000000007;
  }
  
  printf("%lld", sum);
  
  return 0;
}
  
