# coding: utf-8
import sys
import numpy as np

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
H = np.array(lr())
Hmax = np.maximum.accumulate(H)
answer = (H == Hmax).sum()
print(answer)
