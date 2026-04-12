n = int(input())
a = list(map(int, input().split()))

cum = [0] * n
cum[-1] = a[-1]

mod = 10 ** 9 + 7

for i in range(n - 1, 0, -1):
    cum[i - 1] = cum[i] + a[i - 1]

ans = 0

for i in range(1, n):
    num = a[i - 1] * cum[i]
    num %= mod
    ans += num
    ans %= mod

print(ans)
