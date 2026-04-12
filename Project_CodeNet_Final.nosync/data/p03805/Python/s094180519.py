N,M=map(int,input().split())
G=[[] for _ in range(N)]

for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

from itertools import permutations

P=permutations(range(1,N),N-1)

cnt=0
for r in P:
    now=0
    F=True
    for x in r:
        if x in G[now]:
            now=x
        else:
            F=False
    if F:
        cnt+=1
print(cnt)
