import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop

import collections

a,b,c,x,y = map(int,input().split())
"""
AとBのみ
"""
cost = x*a + y*b
"""
ABと個数あわせ
"""
cost2 = c*2*min(x,y)
if x>y:
    cost2 += (x-y)*a
else:
    cost2 += (y-x)*b
"""
ABのみ
"""
cost3 = c*2*max(x,y)
ans = min(cost,cost2)
ans = min(ans,cost3)
print(ans)
