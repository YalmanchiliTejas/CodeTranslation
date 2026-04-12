import numpy as np
import math


H, W = map(int, input().split())

A = np.zeros((H, W), dtype=int)

for h in range(H):
    ah = input()
    for w in range(W):
        if ah[w] == '.':
            A[h][w] = 0
        else:
            A[h][w] = 1

# print(A)
remH = []
remW = []
            
for h in range(H):
    if all(A[h] == 0):
        remH.append(h)
for w in range(W):
    if all(A[:,w] == 0):
        remW.append(w)

# print(remH, remW)
        
ret = []

for h in range(H):
    if h in remH:
        continue
    hlist = []
    for w in range(W):
        if w in remW:
            continue
        # print(h)
        # print(w)
        # print(A[h][w])
        hlist.append(A[h][w])
    ret.append(hlist)

# print(ret)

retH = H - len(remH)
retW = W - len(remW)

# print(retH, retW)
for x in range(retH):
    for y in range(retW):
        if ret[x][y] == 0:
            print('.', end='')
        else:
            print('#', end='')            
    print()
