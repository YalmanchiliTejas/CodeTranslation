
n = int(input())
a = list(map(int, input().split()))

MOD = 10 ** 9 + 7

sum = sum(a) % MOD
ans = 0

for i in range(len(a)):
    sum -= a[i]
    sum %= MOD
    ans += a[i] * sum
    ans %= MOD

print(ans)

