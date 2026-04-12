import sys
sys.setrecursionlimit(10**6)
from math import floor,ceil,sqrt,factorial,log,gcd
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from operator import itemgetter
from fractions import gcd
mod = 10 ** 9 + 7
inf = float('inf')
ninf = -float('inf')

#Pythonを用いる場合
#numpy 1.18.0, scipy 1.4.1, scikit-learn 0.22, numba 0.47.0, networkx 2.4
 
import numpy as np
from scipy.sparse.csgraph import shortest_path, floyd_warshall, dijkstra, bellman_ford, johnson
from scipy.sparse import csr_matrix

 
#整数input
def ii(): return int(sys.stdin.readline().rstrip()) #int(input())
def mii(): return map(int,sys.stdin.readline().rstrip().split())
def limii(): return list(mii()) #list(map(int,input().split()))
def lin(n:int): return [ii() for _ in range(n)]
def llint(n: int): return [limii() for _ in range(n)]
#文字列input
def ss(): return sys.stdin.readline().rstrip() #input()
def mss(): return sys.stdin.readline().rstrip().split()
def limss(): return list(mss()) #list(input().split())
def lst(n:int): return [ss() for _ in range(n)]
def llstr(n: int): return [limss() for _ in range(n)]

#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？

n=ii()
arr=deque(list(sorted([ii() for _ in range(n)])))
cop=deque(deepcopy(list(arr)))
mat=deque([])

for i in range(n):
    if i%4==0:
        p=arr.popleft()
        mat.append(p)
    elif i%4==1:
        p=arr.pop()
        mat.appendleft(p)
    elif i%4==2:
        p=arr.pop()
        mat.append(p)
    else:
        p=arr.popleft()
        mat.appendleft(p)

mat2=deque([])
for i in range(n):
    if i%4==0:
        p=cop.pop()
        mat2.append(p)
    elif i%4==1:
        p=cop.popleft()
        mat2.appendleft(p)
    elif i%4==2:
        p=cop.popleft()
        mat2.append(p)
    else:
        p=cop.pop()
        mat2.appendleft(p)

ans=0
ans1=0
chk=list(mat)
chk1=list(mat2)
for i in range(n-1):
    ans+=abs(chk[i]-chk[i+1])
    ans1+=abs(chk1[i]-chk1[i+1])
print(max(ans,ans1))




