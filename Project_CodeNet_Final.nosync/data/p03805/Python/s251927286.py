from itertools import permutations
n,m=map(int,input().split())
g=[[] for i in range(n)]
for _ in range(m):
  u,v=map(int,input().split())
  g[u-1].append(v-1)
  g[v-1].append(u-1)
ans=0
for v in permutations([int(i) for i in range(n)],n):
  if v[0]!=0:
    continue
  for i in range(n-1):
    if not v[i+1] in g[v[i]]:
      break
  else:
    ans+=1
print(ans)