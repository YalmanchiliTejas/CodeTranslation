# -*- coding utf-8 -*-
N = int(input())
S = input()
K = int(input())

t = S[K - 1]
for s in 'abcdefghijklmnopqrstuvwxyz':
    if s != t:
        S = S.replace(s, '*')
        
print(S)
