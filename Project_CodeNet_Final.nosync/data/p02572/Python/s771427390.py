n = int(input())
a = list(map(int, input().split()))
d = a.copy()
for i in range(n-1):
    d[i+1] += d[i]
ans = 0
mod = 10**9+7
for i in range(n-1):
    ans += a[i]*(d[-1]-d[i])
    ans %= mod
print(ans)