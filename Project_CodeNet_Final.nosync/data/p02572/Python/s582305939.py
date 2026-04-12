n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
ans = 0
b = sum(a)
for i in range(n):
  b -= a[i]
  tmp = (a[i] * b) % mod
  ans = (ans + tmp) % mod
print(ans)