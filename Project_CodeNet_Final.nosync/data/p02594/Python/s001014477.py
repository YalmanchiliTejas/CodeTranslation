from collections import defaultdict,deque
from sys import stdin,setrecursionlimit
import heapq,bisect,math,itertools,string,queue,copy
setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, stdin.readline().split()))

X = int(input())

if X < 30:
    print('No')
else:
    print('Yes')
