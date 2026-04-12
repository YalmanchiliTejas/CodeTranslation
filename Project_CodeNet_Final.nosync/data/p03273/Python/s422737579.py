import os
import sys

aa = input().strip().split()
h = int(aa[0])
w = int(aa[1])
a = [list(input().strip()) for _ in range(h)]
r = [[False for _ in range(i)] for i in [h, w]]

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            r[0][i] = True
            r[1][j] = True

for i in range(h):
    if r[0][i]:
        for j in range(w):
            if r[1][j]:
                sys.stdout.write(a[i][j])

        sys.stdout.write(os.linesep)
