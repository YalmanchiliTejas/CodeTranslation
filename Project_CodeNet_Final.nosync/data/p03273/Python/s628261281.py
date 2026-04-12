import numpy as np
H, W = map(int, input().split())
mat = np.array([list(input()) for _ in range(H)])
mat = mat[:, ~np.where(mat == '.', True, False).all(axis=0)]
mat = mat[~np.where(mat == '.', True, False).all(axis=1)]

print('\n'.join([''.join(row) for row in mat]))
