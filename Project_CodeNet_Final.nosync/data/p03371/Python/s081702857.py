import sys
import itertools
# import numpy as np
import time
import math
 
sys.setrecursionlimit(10 ** 7)
 
from collections import defaultdict
 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

A, B, C, X, Y = map(int, readline().split())

ans = 10 ** 10
for c in range(2 * 10 ** 5 + 1):
    a = X - c // 2
    b = Y - c // 2
    if a < 0:
        a = 0
    if b < 0:
        b = 0
    ans = min(ans, A * a + B * b + C * c)
print(ans)



