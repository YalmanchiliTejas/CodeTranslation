# -*- coding: utf-8 -*-
import numpy as np

H, W = map(int, input().split())
c = 0
b = []
for i in range(H):
    a = list(input())
    if a != ["." for _ in range(W)]:
        b.append(a)
    else:
        c += 1

b = np.array(b)
b_T = b.T

B = []
for i in range(W):
    if list(b_T[i]) != ["." for _ in range(H-c)]:
        B.append(b_T[i])
B = np.array(B)
ans = B.T
for i in range(len(ans)):
    print("".join(map(str, ans[i])))