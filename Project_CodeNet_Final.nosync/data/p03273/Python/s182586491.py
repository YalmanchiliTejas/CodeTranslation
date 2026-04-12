import numpy as np

# input
H, W = map(int, input().split())
A = np.array([list(input()) for _ in range(H)])

B = A[:, np.any(A == '#', axis = 0)]
C = B[np.any(B == '#', axis = 1), :]

for i in range(C.shape[0]):
    print(''.join(C[i]))