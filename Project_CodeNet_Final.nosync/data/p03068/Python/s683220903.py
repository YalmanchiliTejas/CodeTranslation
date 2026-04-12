# -*- coding: utf-8 -*-

N = int(input())
S = input()
K = int(input())
ans = [s if s == S[K-1] else '*' for s in S]

print(''.join(ans))