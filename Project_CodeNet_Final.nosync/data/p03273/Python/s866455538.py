H, W = map(int,input().split())

import numpy as np

matrix = np.empty((0, W), str)
for i in range(0, H):
    matrix = np.append(matrix, np.array([list(input())]), axis = 0)
matrix = matrix[:, np.any(matrix != ".", axis = 0)]
matrix = matrix[np.any(matrix == "#", axis = 1), :]
H, W = matrix.shape
for i in range(0, H):
    print(''.join(matrix[i, :]))