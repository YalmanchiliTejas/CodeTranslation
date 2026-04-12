#!/usr/bin/env python3
# -*- coding: utf-8 -*-

N = input()
H = list(map(int, input().split()))

tmp = H[0]
ans = 1

for i in H[1:]:
    if tmp <= i:
        ans += 1
    tmp = max(tmp, i)

print(ans)
