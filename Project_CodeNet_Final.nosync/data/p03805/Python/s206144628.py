from collections import defaultdict
from itertools import permutations
import sys
sys.setrecursionlimit(10000)
N,M=list(map(int,input().split()))
links=defaultdict(set)
for i in range(M):
    a,b=list(map(int, input().split()))
    links[a].add(b)
    links[b].add(a)
ct=0
for pts in permutations(range(2,N+1),N-1):
    current=1
    for p in pts:
        if  p not in links[current]:
            break
        else:
            current=p
    else:
        ct+=1
print(ct)