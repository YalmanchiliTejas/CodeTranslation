from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
s = list(accumulate(a))
MOD = 10 ** 9 + 7

ans = 0
for i in range(n):
    ans += a[i] * (s[n - 1] - s[i])
    ans %= MOD

print(ans)