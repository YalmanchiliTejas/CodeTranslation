from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())

N = inp()
aa = [inp() for _ in range(N)]

tmp = deque([])
first = True

for a in aa:
    if first:
        tmp.append(a)
        first = False
        continue

    if tmp[0] >= a:
        tmp.appendleft(a)
    else:
        ind = bisect.bisect_left(tmp,a)
        tmp[ind-1] = a

    #print(tmp)

print(len(tmp))
