# -*- coding: utf-8 -*-

import sys
import os
import math

for i, s in enumerate(sys.stdin):
    n = int(s)
    if n == 0:
        break
    elif i != 0:
        print()

    A = []

    for i in range(n):
        lst = input().split()
        name = lst[0]
        w = int(lst[1])
        l = int(lst[2])
        d = int(lst[3])
        score = 3 * w + d
        A.append((score, -i, name))
    A.sort(reverse=True)

    for a in A:
        score = a[0]
        name = a[2]
        print('{},{}'.format(name, score))