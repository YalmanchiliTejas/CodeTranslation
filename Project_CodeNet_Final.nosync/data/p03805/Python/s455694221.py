f=lambda:map(int,input().split())
n,m=f()
g=[[0]*n for _ in range(n)]
for i in range(m):
  a,b=f(); g[a-1][b-1]=g[b-1][a-1]=1
import itertools as it
c=0
for t in it.permutations(range(1,n)):
  p,d=0,1
  for q in t: d*=g[p][q]; p=q
  c+=d
print(c)