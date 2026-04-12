f=lambda:map(int,input().split())
n,m=f()
g=[set() for _ in range(n)]
for i in range(m):
  a,b=f()
  g[a-1].add(b-1)
  g[b-1].add(a-1)
import itertools as it
c=0
for t in it.permutations(range(1,n)):
  p=0
  for q in t:
    if q not in g[p]: break
    p=q
  else: c+=1
print(c)