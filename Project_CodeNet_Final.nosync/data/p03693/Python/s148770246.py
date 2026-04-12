import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
MOD = 10**9 + 7

r,g,b = map(int,input().split())
d = str(r) + str(g) + str(b)
if int(d)%4 == 0:
    print("YES")
else:
    print("NO")