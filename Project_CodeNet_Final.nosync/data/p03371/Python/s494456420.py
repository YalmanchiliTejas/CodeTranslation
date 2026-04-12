import itertools
import math
import sys
import heapq
from collections import Counter
from collections import deque
from fractions import gcd
INF = 1 << 60
sys.setrecursionlimit(10 ** 6)

#ここから書き始める
a, b, c, x, y = map(int, input().split())
ans = min((a + b) * min(x, y), c * min(x, y) * 2)
if x > y:
    ans += min(a * (x - y), c * (x - y) * 2)
else:
    ans += min(b * (y - x), c * (y - x) * 2)
print(ans)