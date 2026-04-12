import math, string, itertools, fractions, heapq, collections, re,  array, bisect, sys, random, time, copy, functools
sys.setrecursionlimit(10**7)
inf = 10 ** 20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def _I(): return int(sys.stdin.readline())
def _F(): return float(sys.stdin.readline())
def pf(s): return print(s, flush=True)

N,M=LI()
AB=[LI() for i in range(M)]
ans=0
L = list(itertools.permutations(range(2,N+1)))
#print(L)
for l in L:
	for lidx in range(len(l)):
		if lidx == 0:
			if [1,l[lidx]] not in AB:
				break
			continue
		
		if [l[lidx-1],l[lidx]] not in AB and [l[lidx],l[lidx-1]] not in AB:
			break
	else:
		ans+=1
print(ans)
	
		
	
	
