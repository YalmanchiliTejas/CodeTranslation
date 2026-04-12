from itertools import permutations
from heapq import *
from collections import defaultdict
from math import log
from itertools import accumulate
from collections import deque
#maxv=[0]
import sys
sys.setrecursionlimit(100100)

import math
from math import ceil
from copy import deepcopy


N,M=map(int,input().split())
T=[[] for i in range(N)]
for i in range(M):
    u,v=map(int,input().split())
    u,v=u-1,v-1
    T[u].append(v)
    T[v].append(u)
list=list(range(1,N))
ans=0
for l in permutations(list):
    t=True
    for i in range(N-1):
        if i==0:
            if not l[0] in T[0]:
                t=False
                break
        else:
            if not l[i] in T[l[i-1]]:
                t=False
                break
    if t:
        ans+=1
print(ans)
