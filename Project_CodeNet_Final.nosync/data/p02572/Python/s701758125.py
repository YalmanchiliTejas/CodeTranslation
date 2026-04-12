n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7

ans = 0
x = a[-1]
for i in reversed(range(n-1)):
   ans += a[i] * x
   ans %= mod
   x += a[i]

print(ans)
