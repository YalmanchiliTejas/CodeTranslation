# coding: utf-8
import sys
import numpy as np

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

H, W = lr()
B = np.array([list(sr()) for _ in range(H)])
A = [[1 if x == '#' else 0 for x in b] for b in B]
row = np.sum(A, axis=1)
column = np.sum(A, axis=0)
r = row != 0
c = column != 0
answer = B[r]
answer = answer[:, c].tolist()
for a in answer:
    print(''.join(a))
