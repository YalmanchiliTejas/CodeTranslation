from itertools import permutations
n,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(m)]
p=[i for i in range(1,n+1)]
np=list(permutations(p))
edge=[[] for i in range(n)]
for i in range(m):
  edge[l[i][0]-1].append(l[i][1]-1)
  edge[l[i][1]-1].append(l[i][0]-1)
ans=0
for i in range(len(np)):
  if np[i][0]!=1:
    continue
  else:
    ok=True
    for j in range(n-1):
      if np[i][j]-1 not in edge[np[i][j+1]-1]:
        ok=False
    if ok:
      ans+=1
print(ans)