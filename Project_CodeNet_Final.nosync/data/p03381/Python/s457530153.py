# -*- coding: utf-8 -*-
n = int(input())
x = [int(i) for i in input().split()]
xx = sorted(x)
mid = n//2-1

d = {}
for i in range(n):
    if i<=mid:
        d[xx[i]] = xx[mid+1]
    else:
        d[xx[i]] = xx[mid]

for i in range(n):
    print(d[x[i]])
