# -*- Coding: utf-8 -*-
N = input()
H = map(int,raw_input().split())


max = H[0]
ans = N
for i in xrange(1,N):
  if H[i-1]>H[i]:
    if max<H[i-1]:
      max = H[i-1]
    ans -= 1
    continue
  if max > H[i]:
    ans -= 1

print ans