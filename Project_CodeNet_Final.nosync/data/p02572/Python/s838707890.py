#!/usr/bin/env python3
n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
sumA = (sum(a) ** 2) % mod
ans = sumA
tmp = 0
for i in range(n):
    tmp += a[i] ** 2
    tmp %= mod
ans = (ans - tmp) % mod
print((pow(2, mod - 2, mod) * ans) % mod)
# print(ans // 2)

