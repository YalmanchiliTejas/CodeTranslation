#!/usr/bin/env python3

n=int(input())  #->n=5
a=list(map(int,input().split()))  #->nl=[1,2,-,n]
mod=int(1e9+7)

# Accumulate
pre=[0]*n
pre[0]=a[0]
for i in range(1,n):  pre[i]=pre[i-1]+a[i]
ans=0
for i in range(1,n):  ans=(ans+(a[i-1]*(pre[n-1]-pre[i-1]))%mod)%mod
print(ans)

