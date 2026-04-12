from sys import stdin
from collections import deque, defaultdict as ddic
from itertools import combinations, permutations, product
import bisect
import heapq

rs = lambda: stdin.readline().strip()
ri = lambda: int(rs())
rsl = lambda: stdin.readline().split()
rim = lambda: map(int, rsl())
ril = lambda: list(rim())

n = ri()
heights = rim()
ans = 0
maximum = float('-inf')
for h in heights:
    if h >= maximum:
        ans += 1
        maximum = h

print(ans)

