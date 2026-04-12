a,b,ab,ax,bx = map(int,input().split())
#a,b,ab,ax,bx = (1500, 2000, 1600, 3, 2)

import math
import sys

abmax = max(ax,bx)*2
candi = list()

for nab in range(abmax,-1,-1):
  na = max(math.ceil(ax - nab * 0.5),0)
  nb = max(math.ceil(bx - nab * 0.5),0)
  candi.append((na,nb,nab))

mincost = candi[0][0]*a + candi[0][1]*b + candi[0][2]*ab

for i in candi:
  cost = i[0]*a + i[1]*b + i[2]*ab
  if(cost < mincost):
    mincost = cost

print(mincost)