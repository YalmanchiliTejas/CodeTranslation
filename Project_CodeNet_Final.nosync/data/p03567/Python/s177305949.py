from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7

def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

S = input()

for i in range(4):
	if S[i:i+2] == 'AC':
		print('Yes')
		sys.exit()

print('No')