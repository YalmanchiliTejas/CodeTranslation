import numpy as np
H, W = map(int, input().split())

lst = []
for i in range(H):
    lst += [list(input())]

arr = np.array(lst)

lstH = []
for i in range(H):
    if all(arr[i,:] == '.'):
        lstH += [i]

arr = np.delete(arr, lstH, 0)

lstW = []
for j in range(W):
    if all(arr[:,j] == '.'):
        lstW += [j]

arr = np.delete(arr, lstW, 1)

for k in arr:
    for l in k:
        print (l, end = '')
    print ()
