N,M=map(int,input().split())
inp=[list(map(int,input().split())) for _ in range(M)]
g=[[] for _ in range(N)]
[g[a-1].append(b-1) for a,b in inp]
[g[b-1].append(a-1) for a,b in inp]
 
from itertools import permutations
seq=[i for i in range(N)]
test=list(permutations(seq))
cnt=0
for t in test:
    if t[0]==0:
        for i in range(N-1):
            if t[i+1] not in g[t[i]]:
                break
        else:
            cnt+=1
print(cnt)