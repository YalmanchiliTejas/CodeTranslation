#!/usr/bin/env python3
# -*- coding: utf-8 -*-

N = input()
S = input()
K = int(input())
K -= 1

a = ''

for i in range(len(S)):
    if S[i] == S[K]:
        a += S[i]
    else:
        a += '*'

print(a)
