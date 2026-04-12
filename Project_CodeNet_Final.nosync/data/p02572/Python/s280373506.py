MOD = 1000000007
n, *a = map(int, open(0).read().split())
wa = a + [0]
for i in range(n-1, 0, -1):
    wa[i-1] += wa[i]

ans = 0
for i in range(n):
    ans += a[i] * wa[i+1]
    ans %= MOD
print(ans)