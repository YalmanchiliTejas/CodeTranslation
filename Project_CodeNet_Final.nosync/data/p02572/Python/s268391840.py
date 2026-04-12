# -*- coding: utf-8 -*-
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
MOD = 10**9+7
N = int(readline())
A = list(map(int,readline().split()))
total = sum(A)
B = [0] * N
for i in range(N):
    B[i] = total-A[i]
ans = 0 
for i in range(N):
    ans += A[i]*B[i]
print((ans//2)%MOD)