"""
author : halo2halo
date : 9, Jan, 2020
"""

import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

N, *H = map(int, read().split())

ans = 0
temp = H[0]
for h in H:
    if h >= temp:
        ans += 1
        temp = h

print(ans)
