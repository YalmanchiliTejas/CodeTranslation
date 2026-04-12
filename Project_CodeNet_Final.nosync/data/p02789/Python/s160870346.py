"""
author : halo2halo
date : 4, Feb, 2020
"""

import sys

# import itertools
# import math

# import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

H, N = map(int, read().split())
print('Yes' if H==N else 'No')