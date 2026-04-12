import sys, math
from collections import defaultdict
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

import collections, bisect
queue = collections.deque()

queue.appendleft(A[0])
for i in range(1, N):
	idx = bisect.bisect_left(queue, A[i])
	if idx == 0:
		queue.appendleft(A[i])
	else:
		queue[idx-1] = A[i]
print(len(queue))
