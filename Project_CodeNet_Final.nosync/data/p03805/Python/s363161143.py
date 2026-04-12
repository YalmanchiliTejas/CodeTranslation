import numpy as np
import itertools #from itertools import *
N,M=map(int,input().split())
G=np.zeros((N+1,N+1),dtype=np.int32)
for i in range(M):
  a,b=map(int,input().split())
  G[a][b]=1
  G[b][a]=1
#print(G)
ans=0
for i in itertools.permutations(range(2,N+1)):
  cnt=0
  for j in range(N-2):
    if G[i[j]][i[j+1]]!=0:
      cnt+=1
  if G[1][i[0]]==1:
    cnt+=1
  if cnt==N-1:
    ans+=1
print(ans)