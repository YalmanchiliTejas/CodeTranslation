from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime,random
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
S = list(input())
K = int(input())

for i,s in enumerate(S):
    if s != S[K-1]:
        S[i] = '*'

print (''.join(S))
