#!/usr/bin/env python3

N = int(input())
A = list(map(int, input().split()))
S = sum(A[1:])
ret = 0
MOD = 10**9 + 7
for i in range(N-1):
    ret += (A[i] * S) % MOD
    S -= A[i+1]

print(ret%MOD)
