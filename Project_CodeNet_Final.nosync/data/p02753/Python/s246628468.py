from collections import defaultdict, deque
import sys, heapq, bisect, math, itertools, string, queue, copy, time
from fractions import gcd
import numpy as np
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7
EPS = 10**-7

s = input()
if s == 'AAA' or s == 'BBB':
    ans = 'No'
else:
    ans = 'Yes'

print(ans)