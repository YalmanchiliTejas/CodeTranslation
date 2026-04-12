n = int(input())
a = [int(i) for i in input().split()]
mod = 10 ** 9 + 7
sm = sum(a) % mod
ans = 0
beki = 0

for i in range(n):
    sm -= a[i]
    ans += a[i] * sm
    ans %= mod
    beki += a[i]*a[i]
    beki %= mod
print(ans)
