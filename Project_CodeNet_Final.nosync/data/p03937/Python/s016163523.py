# -*- coding: utf-8 -*-
H, W = map(int, input().split(' '))
A = [input() for _ in range(H)]

n = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            n += 1

if n == (H + W - 1):
    print('Possible')
else:
    print('Impossible')




