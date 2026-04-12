f=lambda:map(int,input().split())
n,m=f()
g=[[0]*n for _ in range(n)]
for _ in range(m):
  a,b=f()
  g[a-1][b-1]=1
  g[b-1][a-1]=1
from itertools import *
p=[*permutations(range(1,n))]
a=0
for t in p:
  v=0
  for c in t:
    if g[v][c]: v=c
    else: break
  else: a+=1
print(a)