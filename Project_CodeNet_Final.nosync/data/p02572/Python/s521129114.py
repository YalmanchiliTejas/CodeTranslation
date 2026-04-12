n = int(input())
a = list(map(int, input().split()))
t = sum(a)
MOD = 10**9+7
ans = 0
for i in range(n-1):
  t -= a[i]
  ans = (ans+(a[i]*t%MOD))%MOD
print(ans)