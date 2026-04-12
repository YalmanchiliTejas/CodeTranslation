import itertools
import math
import sys
from copy import copy
import numpy as np

h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
skip_col = []
skip_row = []
for i in range(h):
    ok = True
    for j in range(w):
        if (a[i][j] == '#'):
            ok = False
    if (ok):
        skip_col.append(copy(i))

for j in range(w):
    ok = True
    for i in range(h):
        if (a[i][j] == '#'):
            ok = False
    if (ok):
        skip_row.append(copy(j))

xw = w - len(skip_row)
xh = h - len(skip_col)
ans = [['x' for _ in range(xw)] for _ in range(xh)]
xi = 0
xj = 0
for i in range(h):
    xj = 0
    added = False
    for j in range(w):
        if (i not in skip_col and j not in skip_row):
            ans[xi][xj] = a[i][j]
            added = True
            xj += 1
    if added:
        xi += 1

for s in ans:
    print(''.join(s))
