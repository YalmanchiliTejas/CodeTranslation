#!/usr/bin/env python

n = int(input())
a = list(map(int, input().split()))

mod = int(1e9)+7

total = sum(a)
ans = 0 
for i in range(n):
    ans += (a[i]*(total-a[i]))%mod
    total -= a[i]

print(ans%mod)
