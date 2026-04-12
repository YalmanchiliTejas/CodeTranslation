#!/usr/bin/env python3
H, W = map(int, input().split())
a = [''] * H
cnt = 0
for i in range(H):
    a[i] = list(input())
    cnt += len(list(filter(lambda x: x == '#', a[i])))

ans = False
if cnt == H + W - 1:
    y, x = 0, 0
    d = [1, 0, 1]
    for i in range(cnt):
        if y == H - 1 and x == W - 1:
            ans = True
            break
        for j in range(2):
            ny = y + d[j]
            nx = x + d[j + 1]
            if ny < H and nx < W and a[ny][nx] == '#':
                y, x = ny, nx
                break



print('Possible' if (ans) else 'Impossible')
