N = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
s = 0
for i in a:
  s += i
ans = 0
for i in range(N):
  s -= a[i]
  ans += a[i] * s % mod
print(ans%mod)
