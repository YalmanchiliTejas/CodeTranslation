from itertools import permutations

n,m=map(int,input().split())
G=[[] for _ in range(n)]
for _ in range(m):
  a,b=map(int,input().split())
  a-=1
  b-=1
  G[a].append(b)
  G[b].append(a)
ans=0
for P in permutations(range(n),n):
  f=1
  if P[0]!=0:
    continue
  for i in range(n-1):
    if  P[i+1] in G[P[i]]:
      f*=1
    else:
      f*=0
  if f==1:
    ans+=1
print(ans)