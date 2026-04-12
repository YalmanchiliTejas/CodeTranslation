# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

N,X,M=map(int,input().split())
l=[-1]*(M+1)
f=lambda x: (x**2)%M
tmp=X
while l[tmp]==-1:
    res=f(tmp)
    l[tmp]=res
    tmp=res
ans=0
used=[False]*(M+1)
v=X
cnt=0
loop=[]
for cnt in range(1,N+1):
    if used[v]:
        cnt-=1
        break
    used[v]=True
    ans+=v
    v=l[v]
start=v
f=True
dist=0
while f or not v==start:
    f=False
    loop.append(v)
    dist+=v
    v=l[v]
ans+=dist*((N-cnt)//len(loop))
v=start
for _ in range(N-((N-cnt)//len(loop))*len(loop)-cnt):
    ans+=v
    v=l[v]
print(ans)