import sys
from collections import deque, Counter, defaultdict
from itertools import accumulate  # 累積和
from bisect import bisect_left, bisect
from heapq import heappop, heappush  # 優先度付きキュー
from fractions import gcd
from math import ceil, floor, sqrt
from copy import deepcopy

h, w = map(int, input().split())
rows = []
not_skip = defaultdict(bool)
for i in range(h):
    row = input()
    if "#" in row:
        rows.append(row)
        for i in range(w):
            if row[i] == "#":
                not_skip[i] = True

for row in rows:
    for i in range(w):
        if not_skip[i]:
            print(row[i], end="")
    print()
