import math
from operator import itemgetter
import re
import sys
from itertools import accumulate
from collections import defaultdict
from collections import deque
from bisect import bisect_left,bisect
from heapq import heappop,heappush
from fractions import gcd
from copy import deepcopy
input = sys.stdin.readline
N,K = map(int,input().split())
ans = 0
if K == 0:
    print(N**2)
else:
    for b in range(K+1,N+1):
        chk1 = N%b
        chk2 = N//b
        ans += (b-K)*chk2+max(0,chk1-K+1)
    print(ans)