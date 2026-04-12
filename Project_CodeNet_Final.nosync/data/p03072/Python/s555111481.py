#!/usr/bin/env python3

import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)


N = int(input())
H = list(map(int, input().split()))

max_h = 0

count = 0
for h in H:
    if h >= max_h:
        count += 1
    max_h = max(max_h, h)

print(count)
