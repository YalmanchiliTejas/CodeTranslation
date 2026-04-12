import sys, math
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from itertools import combinations, permutations, product
from heapq import heappush, heappop
from functools import lru_cache
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 1000000007
sys.setrecursionlimit(1000000)

N = ri()
A = []
for i in range(N):
	A.append(ri())

queue = deque()

queue.appendleft(A[0])
for i in range(1, N):
	idx = bisect_left(queue, A[i])
	if idx == 0:
		queue.appendleft(A[i])
	else:
		queue[idx-1] = A[i]
print(len(queue))
