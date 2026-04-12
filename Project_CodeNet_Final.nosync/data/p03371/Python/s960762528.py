import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy

a,b,c,x,y = map(int,input().split())

#AとBのみ
cost1 = a*x + b*y
#ABのみ
cost2 = c*max(x,y)*2
#ABとA
cost3 = c*y*2 + abs(x - y)*a
#ABとB
cost4 = c*x*2 + abs(y-x)*b
ans = min(cost1,cost2)
ans = min(ans,cost3)
ans = min(ans,cost4)
print(ans)