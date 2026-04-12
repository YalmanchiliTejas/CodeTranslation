"""
author : halo2halo
date : 16, Jan, 2020
"""

import sys
# import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

N = int(readline())

print('YES' if N==7 or N==5 or N==3 else 'NO')
