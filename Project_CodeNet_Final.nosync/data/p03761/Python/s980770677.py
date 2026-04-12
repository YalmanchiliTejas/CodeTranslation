#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n=int(input())
S=[input() for i in range(n)]
C = collections.Counter(S[0])
for i in range(2,n):
  C1 = collections.Counter(S[i])
  C = C & C1
s=[]
for ci,i in C.items():
  s+=[ci]*i
s.sort()
print(*s,sep="")