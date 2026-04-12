#!/usr/bin/env python3
H, W = map(int, input().split())
a = [None] * H
for i in range(H):
    a[i] = input()

c = [False] * W
r = [False] * H
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            break
        if j == W - 1:
            r[i] = True
for j in range(W):
    for i in range(H):
        if a[i][j] == '#':
            break
        if i == H - 1:
            c[j] = True

s = ''
for i in range(H):
    for j in range(W):
        if r[i] or c[j]:
            continue
        s += a[i][j]
    if not s:
        continue
    print(s)
    s = ''
