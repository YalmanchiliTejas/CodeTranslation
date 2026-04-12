#!/usr/bin/env python3

import sys
input=sys.stdin.readline

mod=10**9+7
n=int(input())
arr=list(map(int,input().split()))
ans=0
sums=sum(arr)
for val in arr:
    ans+=(val*sums)%mod
    ans-=(val*val)%mod
print((ans*pow(2,mod-2,mod))%mod)