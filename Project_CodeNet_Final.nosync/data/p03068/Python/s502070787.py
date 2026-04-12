# -*- coding: utf-8 -*-
N = int(input())
S = input()
K = int(input())

target = S[K - 1]

x = []
for char in S:
    if char != target:
        x.append('*')
    else:
        x.append(char)

print(''.join(x))