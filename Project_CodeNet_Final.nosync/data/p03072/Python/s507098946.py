#!/usr/bin/env python3

N=int(input())
H=list(map(int,input().split()))
memo=0
ans=0
for i in range(N):
    if memo<=H[i]:
        ans+=1
        memo=H[i]
print(ans)
