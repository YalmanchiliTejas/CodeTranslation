import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product, groupby, combinations_with_replacement
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = INT()
A = [INT() for _ in range(N)]
A.sort()
T = deepcopy(A)
T = deque(T)

l = deque([])
l.append(T.popleft())

while T:
	l.appendleft(T.pop())
	if not T:
		break
	l.append(T.pop())
	if not T:
		break
	l.appendleft(T.popleft())
	if not T:
		break
	l.append(T.popleft())

l = list(l)
ans = 0
for i in range(1, N):
	ans += abs(l[i-1]-l[i])

T = deepcopy(A)
T = deque(T)
l = deque([])
l.append(T.pop())
while T:
	l.appendleft(T.popleft())
	if not T:
		break
	l.append(T.popleft())
	if not T:
		break
	l.appendleft(T.pop())
	if not T:
		break
	l.append(T.pop())

l = list(l)
tmp = 0
for i in range(1, N):
	tmp += abs(l[i-1]-l[i])

ans = max(ans, tmp)
print(ans)
