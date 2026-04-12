# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

N = int(input())

H = [int(x) for x in input().split()]

ans = 0

for i in range(N):
    good = True
    for j in range(i):
        if H[j] > H[i]:
            good = False
    ans += good

print(ans)



