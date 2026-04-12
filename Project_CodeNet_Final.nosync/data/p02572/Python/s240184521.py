import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
a=list(map(int,input().split()))

import numpy as np
r=0
s=sum(a)-a[0]
m=7+10**9
for ii in range(n-1):
  r+=(a[ii]*s)%m
  s-=a[ii+1]

#print(m)
print(r%m)
