#!/usr/bin/env python3
# -*- coding: utf-8 -*-
n=int(input())
a=[]
for i in range(0,n):
  a.append(int(input()))
a.sort()

l = a[0]
r = a[0]

li=1
ri=len(a)-1

res = 0

while ri>=li:
  ln = abs(l-a[li])
  lx = abs(l-a[ri])
  rn = abs(r-a[li])
  rx = abs(r-a[ri])

  x = max(ln, max(lx, max(rn, rx)))
  
  if x == ln:
    res = res + ln
    l=a[li]
    li=li+1
  elif x == lx:
    res = res + lx
    l=a[ri]
    ri=ri-1
  elif x == rn:
    res = res + rn
    r=a[li]
    li=li+1
  else:
    res = res + rx
    r=a[ri]
    ri=ri-1

print(res)
