import numpy as np

line = input().split()
H = int(line[0])
W = int(line[1])

array = np.ndarray((H, W), np.uint8)

for i in range(H):
    line = input()
    for j in range(W):
        if line[j] == '.':
            array[i, j] = 0
        elif line[j] == '#':
            array[i, j] = 1

W_condition = np.sum(array, axis=0)!=0
H_condition = np.sum(array, axis=1)!=0

array = array[H_condition, :]
array = array[:, W_condition]

h, w = array.shape

for i in range(h):
    line = ''
    for j in range(w):
        if array[i, j] == 0:
            line += '.'
        elif array[i, j] == 1:
            line += '#'
    print(line)

