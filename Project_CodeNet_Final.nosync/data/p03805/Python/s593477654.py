import itertools

N,M=map(int,input().split())
a=[0]*N
b=[0]*N
C=[[0 for _ in range(N+1)] for _ in range(N+1)]

for i in range(M):
  a,b=map(int,input().split())
  C[a][b]=1
  C[b][a]=1
#print(C)
  
L=[i for i in range(1,N+1)]
#print(L)
ans=0
for v in itertools.permutations(L,len(L)):
  sw=1
  #print(v)
  if v[0]!=1:
    continue
  for i in range(len(v)-1):
    if C[v[i]][v[i+1]]==0:
      sw=0
      break
  if sw==1:
    ans+=1
print(ans)