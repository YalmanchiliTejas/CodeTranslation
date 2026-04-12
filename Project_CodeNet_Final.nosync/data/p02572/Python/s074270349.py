#!/usr/bin/python3
# -*- coding: utf-8 -*-
n = int(input())
a_list = list(map(int, input().split()))
ans = 0
total = 0
mod = 10 ** 9 + 7
for i in range(n):
    total += a_list[i]
    if total >= mod:
        total = total % mod

for i in range(n - 1):
    total -= a_list[i]
    if total < 0:
        total += mod
    ans += a_list[i] * total
    if ans >= mod:
        ans = ans % mod
print(ans)