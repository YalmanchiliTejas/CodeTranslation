import itertools
N,M=map(int,input().split())
edges={tuple(sorted(map(int,input().split()))) for i in range(M)}
ans=0

for i in itertools.permutations(range(2,N+1)):
    l= [1]+ list(i)
    counte = 0
    for edge in zip(l,l[1:]):
        if tuple(sorted(edge)) in edges:
            counte += 1
    if counte == N-1:
        ans+=1

print(ans)