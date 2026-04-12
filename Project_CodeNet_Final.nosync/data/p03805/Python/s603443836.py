N,M=map(int,input().split())
EDGE=[list(map(int,input().split())) for i in range(M)]

EDGELIST=[[] for i in range(N+1)]

for x,y in EDGE:
    EDGELIST[x].append(y)
    EDGELIST[y].append(x)


import itertools

ITER=list(itertools.permutations(range(2,N+1),N-1))
ANS=0

for ite in ITER:
    ROUTE=(1,)+ite

    for j in range(1,N):
        if ROUTE[j] in EDGELIST[ROUTE[j-1]]:
            continue
        else:
            break
    else:
        ANS+=1

print(ANS)