# -*- coding: utf-8 -*-

import sys
import os

A = list(map(int, input().split()))

n = 100 * A[0] + 10 * A[1] + A[2]
if n % 4 == 0:
    print('YES')
else:
    print('NO')