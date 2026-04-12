from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime,random
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
aa = [int(input()) for _ in range(N)]
aa.sort()

if N%2 == 0:
    ans = (sum(aa[N//2:]) - sum(aa[:N//2]))*2 - (aa[N//2]-aa[N//2-1])
    print(ans)
else:
    ans1 = (sum(aa[N//2:]) - sum(aa[:N//2]))*2 - (aa[N//2]+aa[N//2+1])
    ans2 = (sum(aa[(N//2+1):]) - sum(aa[:(N//2+1)]))*2 + (aa[N//2]+aa[N//2-1])
    print(max(ans1,ans2))
