#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import (division, absolute_import, print_function,
                        unicode_literals)
from sys import stdin


def solve(n):
    square = [[0]*n for _ in range(n)]
    x = n // 2
    y = x + 1

    square[y][x] = 1
    for i in range(1, n*n):
        x = (x+1) % n
        y = (y+1) % n
        if square[y][x]:
            x = (x-1) % n
            y = (y+1) % n
        square[y][x] = i + 1

    fmt = ('{:4d}' * n).format
    print('\n'.join(fmt(*row) for row in square))

for line in stdin:
    n = int(line)
    if not n:
        break
    solve(n)