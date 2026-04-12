#!/usr/bin/env python3

import sys
input=sys.stdin.readline

n,x,m=map(int,input().split())
values=[]
s=set()
loop_start=-1
for i in range(n):
    if x in s:
        loop_start=values.index(x)
        break
    values.append(x)
    s.add(x)
    x=(x*x)%m
if loop_start==-1:
    ans=sum(values)
    print(ans)
    exit()
else:
    ans=sum(values[:loop_start])
    loops=values[loop_start:]
    loops_sum=sum(loops)
    n-=loop_start
    l=len(loops)
    ans+=n//l*loops_sum+sum(loops[:n%l])
    print(ans)