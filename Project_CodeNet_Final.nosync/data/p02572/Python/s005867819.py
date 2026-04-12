n = int(input())
a = list(map(int, input().split()))
mod = 1000000007
ans = sum(a) ** 2
for i in range(n):
  ans -= a[i] ** 2
ans //= 2
ans %= mod
print(ans)