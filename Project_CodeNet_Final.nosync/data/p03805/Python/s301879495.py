import sys
from collections import Counter
from collections import deque
import heapq
import math
import fractions
import bisect
import itertools
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n,m=mp()
tree=[[False]*(n+1) for i in range(n+1)]
for i in range(m):
    a,b=mp()
    tree[a][b]=True
    tree[b][a]=True
ans=0
for path in itertools.permutations(range(2,n+1), n-1):
    if tree[1][path[0]]:
        for i in range(n-1):
            if i==n-2:
                ans+=1
                break
            if not tree[path[i]][path[i+1]]:
                break

print(ans)