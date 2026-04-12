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
mat = lambda x, y, v: [[v]*y for _ in range(x)]
ten = lambda x, y, z, v: [mat(y, z, v) for _ in range(x)]
mod = 1000000007
sys.setrecursionlimit(1000000)

N, X, M = rl()

Xs = [None] * M

ans = 0
dif_i = 0
dif_v = 0
cur_i = 0
for i in range(1, N+1):
	ans += X
	if Xs[X] != None:
		cur_i = i
		dif_v = ans - Xs[X][1]
		dif_i = i - Xs[X][0]
		cur_x = X
		break
	Xs[X] = (i, ans)
	X = (X**2) % M
if cur_i > 0 and cur_i < N:
	remain = N - cur_i
	ans += (remain // dif_i) * dif_v
	X = cur_x
	for i in range(remain % dif_i):
		X = (X**2) % M
		ans += X
print(ans)
