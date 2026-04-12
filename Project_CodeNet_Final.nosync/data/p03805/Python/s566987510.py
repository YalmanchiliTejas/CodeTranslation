from itertools import permutations
N,M=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(M)]
g=[[False]*N for i in range(N)]
for a,b in ab:
  g[a-1][b-1]=True
  g[b-1][a-1]=True
nodes=[i for i in range(1,N)]
ans=0
for route in permutations(nodes):
  if g[0][route[0]]== False:
    continue
  for i in range(N-1):
    if i == N-2:
      ans+=1
      
      break
    elif g[route[i]][route[i+1]]:
      continue
    else:
      break
print(ans)
      
    
    
