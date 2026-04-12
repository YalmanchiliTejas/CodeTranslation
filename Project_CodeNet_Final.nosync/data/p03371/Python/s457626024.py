# -*- coding: utf-8 -*-
import sys
# ----------------------------------------------------------------
# Use Solve Function

def solve(lines):
    A,B,C,X,Y = map(int, lines.pop(0).split(' '))
    res = 0
    AB = (A + B)/2
    res = min(AB, C) * min(X, Y) * 2

    diff = abs(X - Y)
    if X > Y:
        res += min(A, 2*C) * diff
    else:
        res += min(B, 2*C) * diff

    print(int(res))

lines = [x.strip() for x in sys.stdin.readlines()]

#
# solve !!
#
solve(lines)