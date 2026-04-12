n,m=map(int,input().split())
G=[[0]*n for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  G[a-1][b-1]=G[b-1][a-1]=1

from itertools import permutations
ans=0
p=list(permutations([x for x in range(1,n)]))
for pp in p:
  ok=True
  t=[0]+list(pp)
  for i in range(1,n):
    if G[t[i-1]][t[i]]==0:
      ok=False
  if ok:ans+=1
print(ans)
