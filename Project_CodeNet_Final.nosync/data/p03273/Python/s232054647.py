# -*- coding: utf-8 -*-
from sys import stdin

ns = lambda: stdin.readline()[:-1] # s = ns()
ni = lambda: int(stdin.readline()) # N = ni()
na = lambda: list(map(int, stdin.readline().split())) # Arr = na()

H, W = na()
Grid = []
for _ in range(H):
    s = ns()
    if '#' in s:
        Grid.append(list(s))

h = len(Grid)
res = []
for i in range(W):
    s = ''
    for j in range(h):
        s += Grid[j][i]
    if '#' in s:
        res.append(s)

for i in range(len(res[0])):
    s = ''
    for j in range(len(res)):
        s += res[j][i]
    print(s)

