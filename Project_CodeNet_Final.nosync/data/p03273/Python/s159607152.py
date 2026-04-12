# -*- coding: utf-8 -*-

import numpy as np

h, w = map(int, input().split())
A = [list(input()) for _ in range(h)]
buf = []
for i in range(h):
    for j in range(w):
        if A[i][j] == '#':
            buf.append(A[i])
            break
ret = []
for j in range(len(buf[0])):
    for i in range(len(buf)):
        if buf[i][j] == '#':
            ret.append([buf[k][j] for k in range(len(buf))])
            break
ans = np.array(ret).T
for line in ans:
    print(''.join(line))
