# -*- coding: utf-8 -*-

N = int(input())
S = input()
K = int(input())

out = ''

for i in range(len(S)):
    if S[i] != S[K-1]:
        out += '*'
    else:
        out += S[i]

print(out)
