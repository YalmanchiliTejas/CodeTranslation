# -*- coding: utf-8 -*-
import sys
# ----------------------------------------------------------------
# Use Solve Function

def solve(lines):
    N = int(lines.pop(0))
    H = list(map(int, lines.pop(0).split(' ')))
    maxh = 0
    res = 0
    for r in H:
        if maxh <= r:
            res += 1
            maxh = r
    print(res)

lines = [x.strip() for x in sys.stdin.readlines()]

#
# solve !!
#
solve(lines)
