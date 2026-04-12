#!/usr/bin/env python3
import sys
sys.setrecursionlimit(1000000)
from collections import deque

# 整数の入力
N = int(input())
#配列の入力
A = list(map(int, input().split()))
ans = 0
S = [0]*N
total = sum(A)
for i in range(N):
    ans += A[i] * (total - A[i])
    total  -= A[i]

print(ans%(10**9+7))
