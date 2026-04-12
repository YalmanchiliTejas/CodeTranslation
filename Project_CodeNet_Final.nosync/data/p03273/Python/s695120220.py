inp = list(map(int, input().split()))
H, W = inp[0], inp[1]

import numpy as np

arr = np.array([[0 if e == '.' else 1 for e in input().split()[0]] for _ in range(H)])

h = []
for i in range(H):
    if (arr[i] == [0] * W).all():
        h.append(i)
ind = np.ones(H, dtype=bool)
ind[h] = False
arr = arr[ind]

w = []
for i in range(len(arr[0])):
    if (arr[:, i] == [0] * len(arr[:,0])).all():
        w.append(i)
ind = np.ones(len(arr[0]), dtype=bool)
ind[w] = False
arr = arr[:, ind]

for i in range(len(arr)):
    txt = ''
    for j in range(len(arr[0])):
        if arr[i][j] == 0:
            txt += '.'
        else:
            txt += '#'
    print(txt)