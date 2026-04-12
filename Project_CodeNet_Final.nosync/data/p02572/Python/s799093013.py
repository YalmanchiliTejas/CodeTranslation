#!/usr/bin/env python3

import sys
input=sys.stdin.readline

mod=10**9+7
n=int(input())
arr=list(map(int,input().split()))
ans=sum(arr)*sum(arr)
for val in arr:
    ans-=(val*val)%mod
print((ans*pow(2,-1,mod))%mod)