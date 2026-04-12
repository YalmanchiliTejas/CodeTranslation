import functools
import numpy as np
H, W = map(int, input().split())
mat = np.array([list(input()) for _ in range(H)])


def get_bool(x, value, axis):
    return np.where(x == value, True, False).all(axis=axis)


mat = mat[:, ~get_bool(mat, '.', 0)]
mat = mat[~get_bool(mat, '.', 1)]
print('\n'.join([''.join(row) for row in mat]))
