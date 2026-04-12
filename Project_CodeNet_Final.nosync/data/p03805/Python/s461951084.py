f=lambda:map(int,input().split())
n,m=f()
g=[set() for _ in range(n)]
for _ in range(m):
  a,b=f()
  g[a-1].add(b-1)
  g[b-1].add(a-1)
from itertools import *
p=[*permutations(range(1,n))]
c=0
for t in p:
  v=0
  for i in t:
    if i in g[v]: v=i
    else: break
  else: c+=1
print(c)