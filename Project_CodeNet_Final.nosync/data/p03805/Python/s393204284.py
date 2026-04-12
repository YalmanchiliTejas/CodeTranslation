import sys
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 8)
from itertools import accumulate
from itertools import permutations
from itertools import combinations
from collections import defaultdict
from collections import Counter
import fractions
import math
from collections import deque
from bisect import bisect_left
from bisect import bisect_right
from bisect import insort_left
import itertools
from heapq import heapify
from heapq import heappop
from heapq import heappush
import heapq
from copy import deepcopy
from decimal import Decimal
alf = list("abcdefghijklmnopqrstuvwxyz")
ALF = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
#import numpy as np
INF = float("inf")
#d = defaultdict(int)
#d = defaultdict(list)
N,M = map(int,input().split())
P = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    P[a].append(b)
    P[b].append(a)
ans = 0
def dfs(cur,d,num):
    global ans
    if num == N:
        ans += 1
        return
    else:
        li = P[cur]
        for chi in li:
            if d[chi] == 1:
                continue
            c = deepcopy(d)
            c[chi] += 1
            dfs(chi,c,num+1)
        return
d = defaultdict(int)
d[0] += 1
dfs(0,d,1)
print(ans)






    
