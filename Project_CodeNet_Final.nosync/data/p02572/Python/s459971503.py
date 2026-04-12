MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
ans, s = 0, sum(a) % MOD
for i in range(n - 1):
    s -= a[i] % MOD
    ans += a[i] * s % MOD
print(ans % MOD)