from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

ans = 0
acc = list(accumulate(a))
for i in range(n - 1):
    ans += a[i] * (acc[-1] - acc[i])
    ans %= mod
print(ans)
