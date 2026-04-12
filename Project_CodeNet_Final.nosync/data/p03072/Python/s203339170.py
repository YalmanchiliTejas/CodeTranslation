#!/usr/bin/env python3
# -*- coding: utf-8 -*-
N = int(input())
Hlist = input().split()
nlist = []
for t in Hlist:
    nlist.append(int(t))
k = nlist[0]
maxlist = [nlist[0]]
p = 1
for t in range(1,len(nlist)):
    if nlist[t] >= max(maxlist):
        p+=1
        maxlist.append(nlist[t])
    else:
        maxlist.append(nlist[t])
print(p)