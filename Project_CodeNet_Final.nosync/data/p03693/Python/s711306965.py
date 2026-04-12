"""
author : halo2halo
date : 30, Jan, 2020
"""

import sys
import itertools

# import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

r, g, b = map(int, readline().split())

print('YES' if (100 * r + g * 10 + b) % 4 == 0 else 'NO')
