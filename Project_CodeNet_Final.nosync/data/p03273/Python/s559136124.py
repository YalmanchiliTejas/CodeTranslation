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

H, W = map(int, input().split())

A = [0] * H
for i in range(H):
    A[i] = list(input())

row = [False] * H
col = [False] * W
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            row[i] = True
            col[j] = True

for i in range(H):
    if not row[i]:
        continue
    for j in range(W):
        if not col[j]:
            continue
        print(A[i][j], end="")
    print()