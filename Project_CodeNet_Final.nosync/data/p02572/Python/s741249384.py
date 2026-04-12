from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))

# 累積和
a_acm = list(accumulate(a[::-1]))

ans = 0
mod = 10 ** 9 + 7
for i in range(n-1):
    ans += a[i] * a_acm[n-2-i]
    ans %= mod
print(ans)
