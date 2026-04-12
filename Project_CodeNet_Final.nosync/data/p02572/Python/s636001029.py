MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
ans, rem = 0, 0
for i in range(n - 1):
    rem += a[n - 1 - i] % MOD
    ans += a[n - 2 - i] * rem % MOD
print(ans % MOD)