#ABC054C
from itertools import permutations

n,m=map(int,raw_input().split())
r=set()
s=set()
for i in xrange(m):
 u,v=map(int,raw_input().split())
 u-=1
 v-=1
 r.add(u)
 r.add(v)
 s.add((u,v))
 s.add((v,u))

res=0
l=list(permutations(r))
for t in l:
 if t[0]!=0:
  continue
 if all((t[i],t[i+1]) in s for i in xrange(n-1)):
  res+=1
   
print res
