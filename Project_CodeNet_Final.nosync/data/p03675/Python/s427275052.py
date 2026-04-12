#!/usr/bin/env pypy3
# -*- coding: UTF-8 -*-

n=int(input())
l=[int(i) for i in input().split()]

ans=[]
if n%2:
    for i in range(n-1,-1,-2):
        ans.append(l[i])
    for i in range(1,n,2):
        ans.append(l[i])
else:
    for i in range(n-1,0,-1):
        if i%2:
            ans.append(l[i])
    for i in range(n-1):
        if i%2==0:
            ans.append(l[i])

print(*ans)