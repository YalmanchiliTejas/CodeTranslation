import sys
from collections import defaultdict, Counter, namedtuple, deque
import itertools
import functools
import bisect
import heapq
import math
import copy
# from fractions import gcd

MOD = 10 ** 9 + 7
# MOD = 998244353
# sys.setrecursionlimit(10**8)

n = int(input())
A = list(map(int, input().split()))

su = [0]*n
su[-1] = A[-1]
for i in reversed(range(n-1)):
    su[i] = (A[i]+su[i+1])%MOD

ans = 0
for i in range(n-1):
    ans = (ans + A[i]*su[i+1])%MOD

print(ans)
