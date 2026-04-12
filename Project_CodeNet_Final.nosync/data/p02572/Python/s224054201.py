#!/usr/bin/env python3
import os
from sys import stdin, stdout
    
    
def solve(tc):
    MOD = int(1e9) + 7
    n = int(stdin.readline().strip())
    seq = list(map(int, stdin.readline().split()))

    suffix = [0 for i in range(n)]
    suffix[n-1] = seq[n-1]
    for i in range(n-2, -1, -1):
        suffix[i] = suffix[i+1] + seq[i]
    
    ans = 0
    for i in range(n-1):
        ans += seq[i] * suffix[i+1]
        ans %= MOD
    
    print(ans)


    
tcs = 1
tc = 1
while tc <= tcs:
    solve(tc)
    tc += 1