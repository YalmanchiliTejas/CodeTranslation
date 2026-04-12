import numpy as np
H, W = map(int, input().split())
A = np.array([list(input()) for _ in range(H)])
del_i = []
for i in range(H):
    if all(A[i, :] == '.'):
        del_i.append(i)
del_j = []
for j in range(W):
    if all(A[:, j] == '.'):
        del_j.append(j)
A = np.delete(A, del_i, 0)
A = np.delete(A, del_j, 1)
for i in range(A.shape[0]):
    print(''.join(A[i]))