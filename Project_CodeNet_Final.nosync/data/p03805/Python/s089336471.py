import itertools

N,M=map(int,input().split())
route=[list(map(int,input().split())) for _ in range(M)]
candidate=list(itertools.permutations(range(1,N+1)))

ans=0
for c in candidate:
  if c[0]==1:
    for i in range(N-1):
      l=sorted([c[i], c[i+1]])
      if l not in route:
         break
    else:
      ans+=1
print(ans)

