# -*- coding: utf-8 -*-

import sys
import os
import math

for s in sys.stdin:
    n = int(s)
    if n == 0:
        break

    M = [[None for i in range(n)] for j in range(n)]

    # 1
    x = n // 2
    y = n // 2 + 1
    M[y][x] = 1
    x = x + 1
    y = y + 1
    counter = 2

    while counter < n * n + 1:

        if x >= n:
            x = 0
        elif x < 0:
            x = n - 1

        if y >= n:
            y = 0
        elif y < 0:
            y = n - 1

        if M[y][x] is not None:
            x -= 1
            y += 1
        else:
            M[y][x] = counter
            counter += 1
            x += 1
            y += 1

    for row in M:
        for v in row:
            print(str(v).rjust(4), end='')
        print()