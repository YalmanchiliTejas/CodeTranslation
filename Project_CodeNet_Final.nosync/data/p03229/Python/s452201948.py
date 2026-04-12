from math import ceil,floor,factorial,gcd,sqrt,log2,cos,sin,tan,acos,asin,atan,degrees,radians,pi,inf
from itertools import accumulate,groupby,permutations,combinations,product,combinations_with_replacement
from collections import deque,defaultdict,Counter
from bisect import bisect_left,bisect_right
from operator import itemgetter
from heapq import heapify,heappop,heappush
from queue import Queue,LifoQueue,PriorityQueue
from copy import deepcopy
from time import time
import string
import sys
sys.setrecursionlimit(10 ** 7)
def input() : return sys.stdin.readline().strip()
def INT()   : return int(input())
def MAP()   : return map(int,input().split())
def LIST()  : return list(MAP())

n = INT()
a = []
for i in range(n):
    a.append(INT())

a.sort()
qa = deque(a)
qb = deque()

for i in range(len(qa)):
    if i % 4 == 0:
        qb.appendleft(qa.popleft())
    elif i % 4 == 1:
        qb.append(qa.pop())
    elif i % 4 == 2:
        qb.appendleft(qa.pop())
    else:
        qb.append(qa.popleft())

ans = 0
reg = inf
for i in range(len(qb)):
    if i < len(qb) - 1:
        tmp = abs( qb[i+1] - qb[i] )
    else:
        tmp = abs( qb[0] - qb[i])
    ans += tmp
    reg = min(reg, tmp)
ans -= reg
print(ans)