from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime,random
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
H = inpl()

cnt = 0
for i in range(N):
    for j in range(i):
        if H[i] < H[j]:
            break
    else:
        cnt += 1
print(cnt)
