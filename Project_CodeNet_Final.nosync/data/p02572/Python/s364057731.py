n = int(input())
a = list(map(int, input().split()))

MOD = 10**9+7
cum = [0 for _ in range(n)]
cum[0] = a[0]
for i in range(1, n):
    cum[i] = cum[i-1]+a[i]

ans = 0
for i in range(n):
    ans += a[i]*(cum[n-1]-cum[i])
    ans %= MOD
print(ans)