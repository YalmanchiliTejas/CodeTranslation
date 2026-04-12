"""
author : halo2halo
date : 29, Jan, 2020
"""

import sys

# import itertools
# import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

X, Y, Z = map(int, readline().split())
print((X-Z) // (Y + Z))