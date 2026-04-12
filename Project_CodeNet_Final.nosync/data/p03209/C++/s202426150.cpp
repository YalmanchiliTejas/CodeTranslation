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
  if(x==0) return 0;
  if(n==0) return 1;
  if(x<=n) return 0;
  long long st = pow2(n+1) - 1, ans;//每行面包 肉饼个数和 的一半 包括中间的
  if (n>=1)
  {
    if (x >= st){
      ans = pow2(n) + solve(n-1, x-st);
    }
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
