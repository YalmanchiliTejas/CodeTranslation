from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

H,W = inpl()
MAP = [list(input()) for i in range(H)]
xx = []
yy = []

for x in range(W):
	for y in range(H):
		if MAP[y][x] == '.':
			continue
		else:
			break
	else:
		xx.append(x)

for y in range(H):
	for x in range(W):
		if MAP[y][x] == '.':
			continue
		else:
			break
	else:
		yy.append(y)

ans = []
for y in range(H):
	if y in yy:
		continue
	tmp = []
	for x in range(W):
		if x in xx:
			continue
		tmp.append(MAP[y][x])
	ans.append(tmp)

for azu in ans:
	print(''.join(azu))
