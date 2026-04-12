import math
import sys
from collections import deque
import copy
import itertools
from itertools import permutations
def mi() : return map(int,input().split())
def i() : return int(input())
a,b=mi()
ans=0
l=[[] for _ in range(a)]
for i in range(b):
  u,v=mi()
  l[u-1].append(v-1)
  l[v-1].append(u-1)
S=[]
for i in range(1,a):
  S.append(i)
lst=list(permutations(S))
for i in lst:
  x=0
  t=True
  for w in range(len(i)):
    if not i[w] in l[x]:
      t=False
      break
    x=i[w]
  if t:
    ans+=1
print(ans)