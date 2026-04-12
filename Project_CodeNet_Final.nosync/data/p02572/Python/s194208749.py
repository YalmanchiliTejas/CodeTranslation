n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

s = sum(a)
ans = 0

for i in range(n-1):
  s -= a[i]
  ans += a[i]*s % mod
  ans = ans % mod

print(ans % mod)