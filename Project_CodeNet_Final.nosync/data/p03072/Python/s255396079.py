# -*- coding: utf-8 -*-
import numpy as np
N = int(input())
H = np.array(list(map(int, input().split())))
sum = 1
for i in range(1, N):
  max_hight = np.max(H[:i])
  if(H[i] >= max_hight):
    sum += 1

print(sum)
