import sys
import itertools
# import numpy as np
import time
import math
import heapq
from collections import defaultdict
from collections import Counter
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 10 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())
N, X, M = map(int, input().split())

xs = [0] * M
cur = X
cicle = 0
A = []
for i in range(M + 5):
    v = cur % M 
    if xs[v] != 0:
        A.append(v)
        cicle = i
        break
    xs[v] += 1
    A.append(v)
    cur *= cur
    cur %= M

start = 0
for i in range(cicle):
    if A[i] == A[-1]:
        start = i
# print(start)
# print(A)
l = cicle - start
ans = sum(A[0:start])
ans += ((N - start) // l) * sum(A[start:-1])
ans += sum(A[start:start+((N - start) % l)])

print(ans)

