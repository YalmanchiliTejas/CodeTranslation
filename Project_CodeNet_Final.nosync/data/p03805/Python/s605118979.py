n,m=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(m)]
import itertools
ans=0
l = [i for i in range(1,n+1)]
p = itertools.permutations(l, n)
for v in p:
  v=list(v)
  if v[0]!=1:
    continue
  x=0
  for i in range(n-1):
    w=v[i:i+2]
    w.sort()
    if w not in ab:
      x=1
      break
  if x==0:
    ans+=1
print(ans)