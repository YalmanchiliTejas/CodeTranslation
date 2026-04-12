f=lambda:map(int,input().split())
n,m=map(int,input().split())
g=[[0]*n for _ in range(n)]
for i in range(m):
  a,b=f()
  g[a-1][b-1]=1
  g[b-1][a-1]=1
import itertools as it
c=0
for t in it.permutations(range(1,n)):
  p=0
  for q in t:
    if g[p][q]<1: break
    p=q
  else: c+=1
print(c)