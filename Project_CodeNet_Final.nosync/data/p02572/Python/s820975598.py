import sys
input = sys.stdin.readline
import numpy as np
mod = 1000000000+7
n = int(input())
A = [int(a) for a in input().strip().split()]
s = sum(A)%mod
S = 0

for a in A:
    s = s-a
    S += (s*a)%mod
S = S%mod
print(S)
