import sys
import math
import itertools
def input():
    return sys.stdin.readline()[:-1]

n,m=map(int,input().split())
g = [[]for i in range(n)]
lis = [i for i in range(2,n+1)]

for i in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
ans=0
for i in itertools.permutations(lis):
    now = 0
    jud = True
    for j in list(i):
        if j-1 not in g[now]:
            jud = False
            continue
        else:
            now = j-1

    if jud==True:
        ans+=1

print(ans)
