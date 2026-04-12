import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

x,y,z = map(int,input().split())
x-= 2*z
ans = x//(y+z)
if x%(y+z)>=y:
    ans += 1
print(ans)