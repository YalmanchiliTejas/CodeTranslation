# -*- coding: utf-8 -*-
# map(int, input().split())
N = int(input())
A = list(map(int, input().split()))

mod = pow(10,9)+7

ruiseki = [0]
for a in A:
    ruiseki.append((ruiseki[-1]+a)%mod)

total = 0
for i in range(1,N+1):
    bubun_sum = (ruiseki[-1]-ruiseki[i])%mod
    bubun_total = (A[i-1]*bubun_sum)%mod
    total = (total+bubun_total)%mod

print(total)