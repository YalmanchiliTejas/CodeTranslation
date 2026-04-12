#!/usr/bin/env python3.4
# -*- coding: utf-8 -*-

# abc124_b

# input
n = int(input())
Hs = [int(s) for s in input().split()]
# output
m = -1
count = 0
for h in Hs:
    if h>=m:
        m = h
        count += 1
ans = count
print(ans)

