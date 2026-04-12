#include <stdio.h>
long long solve(long long, long long);
long long pow2(long long);
long long a[5] = {0, 1, 2, 3, 3};
int main()
{
  long long n, x;
  scanf("%lld%lld", &n, &x);
    long long ans;
  ans = solve(n, x);
  printf("%lld\n",ans);
  return 0;
}
long long solve(long long n, long long x)
{
  if (n==1)
  {
    return a[x-1];
  }
  long long st = pow2(n+1) - 1, ans;//每行面包 肉饼个数和 的一半 包括中间的
  if (n>1)
  {
    if (x > st){
      // printf("st = %lld\n", st);
      // printf("n-1 = %lld x-st = %lld solve(n-1, x-st) = %lld\n", n-1, x-st, solve(n-1, x-st-1));
      // printf("pow2(n) = %lld\n", pow2(n));
      if (x-st < pow2(n+1)-2)
        ans = pow2(n)-1 + 1 + solve(n-1, x-st);//2 13
      else
        ans = pow2(n)-1 + 1 + solve(n-1, x-st-1);//2 13
      // printf("ans = %lld\n", ans);
    }
    else if(x == st)
      ans = pow2(n);
    else{
      ans = solve(n-1, x-1);
    }
  }
  return ans;
}
long long pow2(long long n)
{
  long long x = 1;
  for (int i = 0; i < n; ++i)
    x *= 2;
  return x;
}