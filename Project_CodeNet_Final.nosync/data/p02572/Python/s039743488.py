#!/usr/bin/env python3

import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

MOD = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

A = [a % MOD for a in A]
A_d = [(a * a) % MOD for a in A]
res = ((sum(A)**2) % MOD - sum(A_d) % MOD) % MOD
res = res * pow(2, MOD-2, MOD)
res %= MOD

print(res)
