# -*- coding: utf-8 -*-
import sys,re
# ----------------------------------------------------------------
# Use Solve Function

def solve(lines):
    N = int(lines.pop(0))
    S = lines.pop(0)
    K = int(lines.pop(0))
    c = S[K-1:K]
    print(re.sub(r"[^{}]".format(c),'*',S))

lines = [x.strip() for x in sys.stdin.readlines()]
solve(lines)