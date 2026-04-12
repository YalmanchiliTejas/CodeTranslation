import sys
input = sys.stdin.readline
n,m=map(int,input().split())
g=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
from itertools import permutations
P=list(permutations(range(n)))
#print(P)
cnt=0
for p in P:
    if p[0]!=0:
        continue
    flg=True
    for i in range(len(p)-1):
        #print(p)
        if p[i] not in g[p[i+1]]:
            flg=False
    if flg:
        cnt+=1
print(cnt)
