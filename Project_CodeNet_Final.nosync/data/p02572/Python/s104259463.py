#!/usr/bin/env python
# -*- coding: utf-8 -*-

N = int(input())
A_list = list(map(int, input().split()))
ans = 0
SUM = sum(A_list)
for i in range(N):
    SUM -= A_list[i]
    if i != N -1:
        ans += A_list[i] * SUM
while ans >= 10 ** 21 + 7000000000000:
    ans -= 10 ** 21 + 7000000000000
while ans >= 10 ** 19 + 70000000000:
    ans -= 10 ** 19 + 70000000000
while ans >= 10 ** 17 + 700000000:
    ans -= 10 ** 17 + 700000000
while ans >= 10 ** 15 + 7000000:
    ans -= 10 ** 15 + 7000000
while ans >= 10 ** 13 + 70000:
    ans -= 10 ** 13 + 70000
while ans >= 10 ** 11 + 700:
    ans -= 10 ** 11 + 700
while ans >= 10 ** 9 + 7:
    ans -= 10 ** 9 + 7
print(ans)
