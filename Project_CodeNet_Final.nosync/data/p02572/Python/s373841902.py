import sys,itertools,collections,bisect
from collections import deque,Counter,defaultdict
from heapq import heappush,heappop,heapify
read=sys.stdin.readline
sys.setrecursionlimit(10**6)

MOD=10**9+7
N=int(input())
A=list(map(int,input().split()))
cum=[0]*(N+1)
for i in range(N):
    cum[i+1]=(cum[i]+A[i])%MOD

ans=0
for i in range(N):
    res=(cum[N]-cum[i+1]+MOD)%MOD*A[i]%MOD
    ans=(ans+res)%MOD
print(ans)
