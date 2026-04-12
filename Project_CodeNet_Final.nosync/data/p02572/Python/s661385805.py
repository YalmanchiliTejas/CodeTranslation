n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0
total = sum(a)
for i in range(n):
    total -= a[i]
    ans += a[i]*total
    ans %= mod
print(ans)
