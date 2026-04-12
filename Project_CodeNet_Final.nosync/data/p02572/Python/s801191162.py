MOD = 10 ** 9 + 7

n = int(input())
a = list(map(int, input().split()))

ans = (a[0] * a[1]) % MOD
s = a[0]
for i in range(2, n):
    s = (s + a[i-1]) % MOD
    ans += (s * a[i]) % MOD
    ans %= MOD

print(ans)