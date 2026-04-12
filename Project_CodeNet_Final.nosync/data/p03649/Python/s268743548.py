# -*- coding: utf-8 -*-
import numpy as np


N = int(input())
a = np.array([int(n) for n in input().split()])

total = 0

while a.max() >= N:
    add = (a//N).sum() - (a//N)
    total += (a//N).sum()
    a = a%N
    a += add

print(total)