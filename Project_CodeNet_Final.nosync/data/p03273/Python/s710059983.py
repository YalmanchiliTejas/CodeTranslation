import numpy as np
H, W = map(int, input().split())
mat = np.array([list(input()) for _ in range(H)])
bools = np.where(mat == '.', True, False)
mat = mat[:, ~bools.all(axis=0)]
bools = np.where(mat == '.', True, False)
mat = mat[~bools.all(axis=1)]

print('\n'.join([''.join(row) for row in mat]))
