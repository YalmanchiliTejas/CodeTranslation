ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
tma = lambda :tuple(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
import collections
import math
import itertools
import heapq as hq
ceil = math.ceil
n = ni()
A = lma()
mod=10**9+7
tot = 0
for a in A:
    tot = (tot+a)%mod
ans = 0
for a in A:
    tot =(tot-a)%mod
    ans+=(tot*a)%mod
print(ans%mod)
