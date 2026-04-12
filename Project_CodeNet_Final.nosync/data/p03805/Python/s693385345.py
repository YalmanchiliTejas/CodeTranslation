n,m=map(int,input().split())
ab=[list(map(int,input().split())) for _ in [0]*m]
g=[[] for _ in [0]*n]
[g[a-1].append(b-1) for a,b in ab]
[g[b-1].append(a-1) for a,b in ab]

from itertools import permutations

cnt=0
for i in permutations(range(1,n)):
    i=(0,)+i
    for j in range(n-1):
        if i[j+1] not in g[i[j]]:
            break
    else:
        cnt+=1
print(cnt)