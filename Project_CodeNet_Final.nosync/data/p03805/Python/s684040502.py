import itertools
N,M=map(int,input().split())
edge=[]
for i in range(N+1):
  edge.append([0]*(N+1))
for j in range(M):
  a,b=map(int,input().split())
  edge[a][b]=1
  edge[b][a]=1
roots=list(itertools.permutations(range(2,N+1)))
ans=0
for root in roots:
  pos=1
  for i in range(N-1):
    nxt=root[i]
    if edge[pos][nxt]==1:
      pos=nxt
    else:
      break
  else:
    ans+=1
print(ans)
  