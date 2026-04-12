from collections import defaultdict as dd
from itertools import permutations as pe

d=dd(list)
n,m=map(int,input().split())

for _ in range(m):
  a,b=map(int,input().split())
  d[a].append(b)
  d[b].append(a)

c=0

for i in pe(range(2,n+1)):
  a=d[1]
  f=True
  for j in i:
    if not j in a:
      f=False
      break
    else:
      a=d[j]
  if f:c+=1

print(c)