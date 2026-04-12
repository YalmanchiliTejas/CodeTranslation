# /usr/bin/python
# -*- coding: utf-8 -*-
#
import sys
import math


n,x = map(int, input().split())

cntr = [1]
keta = [1]

for i in range(n):
  cntr.append(cntr[-1]*2+1)
  keta.append(keta[-1]*2+3)

ans = 0
for i in range(n,-1,-1):
  if x >= cntr[i]:
    ans += 2**i
    x -= cntr[i]
  else:
    x -= 1
print(ans)