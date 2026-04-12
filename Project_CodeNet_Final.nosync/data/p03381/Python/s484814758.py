#!/usr/bin/env python
import numpy as np
N = int(input())
X = np.array(list(map(int, input().split())))
idx = X.argsort()
low = idx[N//2-1]
high = idx[N//2]

res = np.zeros(N, dtype=int)
res[idx[:N//2]] = X[high]
res[idx[N//2:]] = X[low]

for i in range(N):
    print(res[i])