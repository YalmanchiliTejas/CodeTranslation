import itertools
n,m=map(int,input().split())
G=[[0]*n for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  G[a-1][b-1]=1
  G[b-1][a-1]=1
S=""
for i in range(1,n):
  S=S+str(i)
ans=0
for x in itertools.permutations(S):
  a=0
  if G[0][int(x[0])]==0:
    a=1
  for i in range(n-2):
    if G[int(x[i])][int(x[i+1])]==0:
      a=1
  if a==0:
    ans=ans+1
print(ans)