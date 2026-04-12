n = int(input())
a = list(map(int, input().split()))
MOD = int(1e9+7)
k = (MOD + 1) // 2

ans = sum(a)**2 % MOD
for ai in a:
    ans -= ai**2
    ans %= MOD
ans *= k
ans %= MOD
print(ans)