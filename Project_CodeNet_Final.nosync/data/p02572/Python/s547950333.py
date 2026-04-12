n = int(input())
a = list(map(int, input().split()))

mod = 1000000007
s = 0
for i in range(n):
  s += a[i]
  s %= mod

ans = 0
for i in range(n):
  s -= a[i]
  if s < 0:
    s += mod
  ans += a[i] * s
  ans %= mod
print(ans)
         