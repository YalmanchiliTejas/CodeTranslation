import numpy as np
from copy import deepcopy
from heapq import heappop, heappush
from bisect import bisect_left, bisect
from collections import Counter, defaultdict, deque
from itertools import product, permutations, combinations

N = int(input())
A = list(map(int, input().split()))

s = 0

S = [0]

for i in range(N):
    S.append(A[i] + S[i])

for i in range(N):
    s += A[i] * S[i]

print(s % (10**9 + 7))
exit()
