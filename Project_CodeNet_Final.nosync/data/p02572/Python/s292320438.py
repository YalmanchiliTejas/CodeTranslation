#!/usr/bin/env python

n = int(input())
a = list(map(int, input().split()))
mod = int(1e9)+7

s = sum(a)
ans = sub = 0 
for i in range(n):
    ans += a[i]*s
for i in range(n):
    sub += a[i]*a[i]
ans = ((ans-sub)//2)%mod
print(ans)
