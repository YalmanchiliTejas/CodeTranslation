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


x = set()
for i in range(H):
    if all(True if a == '.' else False for a in A[i]):
        x.add(i)

ans = []
for i in range(H):
    if i in x:
        continue
    ans.append(A[i])

A = ans
x = set()
for i in range(W):
    if all(True if A[j][i] == '.' else False for j in range(len(A))):
        x.add(i)

ans = []
for i in range(len(A)):
    z = []
    for j in range(W):
        if j not in x:
            z.append(A[i][j])
    ans.append(z)

for i in ans:
    print("".join(i))