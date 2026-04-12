# -*- coding: utf-8 -*-
import numpy as np

N = int(input())
if (isinstance(N, int) != True) or (N < 1) or (N > 20):
    exit()
h = np.array([int(i) for i in input().split()])
if (np.any(h<1)==True) or (np.any(h>100)==True):
    exit()
c = 0
for j in range(len(h)):
    if j == 0:
        max = h[0]
        c += 1
        pass
    elif h[j] >= max:
        max = h[j]
        c += 1
print(c)
