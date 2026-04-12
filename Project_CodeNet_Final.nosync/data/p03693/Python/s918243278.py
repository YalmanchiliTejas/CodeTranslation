#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf')
ans = 0 ;count = 0 ;pro = 1

r,g,b=input().split()
a=r+g+b
if int(a)%4==0:
    print("YES")
else:
    print("NO")