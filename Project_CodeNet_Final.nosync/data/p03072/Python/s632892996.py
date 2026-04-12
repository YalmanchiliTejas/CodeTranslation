# /usr/bin/python
# -*- coding: utf-8 -*-
#
import math


n = int(input())
hn = list(map(int, input().split()))
mx = 0
ans = 0
for h in hn:
  if mx <= h:
    ans += 1
    mx = h

print(ans)