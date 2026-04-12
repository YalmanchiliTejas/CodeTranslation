from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())

A,B,C,X,Y = inpl()

#X<=Yに固定
if X > Y:
	X,Y = Y,X
	A,B = B,A

ans = 0
if A+B <= C*2: #セットがゴミ
	ans += X*A + Y*B
else:
	ans += X*2*C
	Y -= X
	ans += min(B*Y,C*2*Y)

print(ans)