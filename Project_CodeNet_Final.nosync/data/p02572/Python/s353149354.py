n = int(input())
a = list(map(int, input().split()))
s = 0
ans = 0
mod = 10**9 + 7
for i in range(n):
  ans = (ans + a[i] * s) % mod
  s = (s + a[i]) % mod
print(ans)