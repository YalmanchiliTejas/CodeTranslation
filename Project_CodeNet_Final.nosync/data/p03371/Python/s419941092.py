#!/usr/bin/env python3
import sys, math
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
sys.setrecursionlimit(10**8)
inf = float('inf')
ans=count=0
f=g=h=0
a,b,c,x,y=map(int,input().split())
if a+b>2*c:
    f=1
if a>2*c:
    g=1
if b>2*c:
    h=1

if f:
    ans+=min(x,y)*c*2
    if x>=y:
        if g==1:
            ans+=(x-y)*c*2
        else:
            ans+=(x-y)*a
    else:
        if h==1:
            ans += (y-x)*c*2
        else:
            ans+=(y-x)*b
else:
    if g:
        ans+=x*2*c+y*b
    elif h:
        ans+=x*a+y*2*c
    else:
        ans+=x*a+y*b
print(ans)

