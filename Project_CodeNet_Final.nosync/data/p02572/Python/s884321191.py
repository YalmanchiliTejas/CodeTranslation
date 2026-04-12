n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7

summ = 0
ans = 0
for i in range(1, n):
    summ += a[-i]
    ans += a[-(i + 1)] * summ
    ans %= MOD

print(ans % MOD)
