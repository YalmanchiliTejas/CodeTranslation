n = int(input())
a = list(map(int, input().split()))
MOD = pow(10, 9) + 7
pairs = sum(a)

ans = 0
for i in range(n - 1):
    pairs -= a[i]
    ans += a[i] * pairs
    ans %= MOD

print(ans)
