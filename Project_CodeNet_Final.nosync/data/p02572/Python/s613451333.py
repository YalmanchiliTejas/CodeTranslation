import itertools
n = int(input())
a = list(map(int,input().split()))
cumsum = list(itertools.accumulate(a))
ans = 0
mod = 10**9+7
for i in range(1,n):
  ans += a[i]*cumsum[i-1]
print(ans%mod)