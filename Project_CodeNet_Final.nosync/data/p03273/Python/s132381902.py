#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
h,w=map(int,input().split())
l=["" for i in range(w)]
yo=[]
for i in range(h):
    s=input()
    for a,j in enumerate(s):
        l[a]+=j
for i in l:
    if "#" in i:
        yo.append(i)
x=len(yo[0])
ans=["" for i in range(x)]
for i in yo:
    for a,j in enumerate(i):
        ans[a]+=j
for i in ans:
    if "#" in i: print(i)