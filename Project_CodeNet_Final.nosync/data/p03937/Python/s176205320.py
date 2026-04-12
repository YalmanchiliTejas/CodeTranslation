from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

H,W = inpl()
MAP = [['.']*(W+2)]
for i in range(H):
	MAP.append(['.'] + list(input()) + ['.'])
MAP.append(['.']*(W+2))

x = y = 1
while x < W or y < H:
	ri = MAP[y][x+1]
	do = MAP[y+1][x]
	le = MAP[y][x-1]
	up = MAP[y-1][x]
	if ri == do or [ri,do,le,up].count('#')>2:
		print('Impossible')
		sys.exit()
	else:
		if ri == '#':
			x += 1
		else:
			y += 1


ri = MAP[y][x+1]
do = MAP[y+1][x]
le = MAP[y][x-1]
up = MAP[y-1][x]

if [ri,do,le,up].count('#')>=2:
	print('Impossible')
else:
	print('Possible')
