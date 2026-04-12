# -*- coding: utf-8 -*-
N = int(input())
S = list(str(input()))
K = int(input())

for i in range(N):
    if S[i] != S[K - 1]:
        S[i] = "*"

Z = ''.join(S)
print(Z)