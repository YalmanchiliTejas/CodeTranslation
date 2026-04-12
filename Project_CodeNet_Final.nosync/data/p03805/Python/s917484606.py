import itertools
N,M=map(int,input().split())
ab=list(list(map(int,input().split())) for _ in range(M))
l=list(l for l in range(1,N+1))
numlist=list(itertools.permutations(l))
ans=0
for I in numlist:
    if I[0]==1 and all(sorted([I[j],I[j+1]]) in ab for j in range(N-1)):
        ans+=1
print(ans)
