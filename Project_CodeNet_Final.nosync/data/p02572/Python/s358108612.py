# coding:utf-8
import itertools
n = int(input())
a = list(map(int, input().split()))
cum = [0] + list(itertools.accumulate(a))
# print(cum)
ans = 0
mod = 10**9 + 7

for i in range(n):
    ans += a[i] * cum[i]
    # print(a[i], cum[i])

print(ans % mod)
