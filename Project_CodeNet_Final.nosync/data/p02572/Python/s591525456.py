n, *a = map(int, open(0).read().split())
MOD = 10**9 + 7
tmp = sum(a) % MOD
ans = 0
for i in range(n-1):
    tmp -= a[i]
    ans += tmp * a[i] % MOD
    ans = ans % MOD
print(ans)