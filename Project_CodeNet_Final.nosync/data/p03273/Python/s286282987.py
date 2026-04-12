import functools
import numpy as np


def get_bool(x, value, axis):
    return np.where(x == value, True, False).all(axis=axis)


H, W = map(int, input().split())
mat = np.array([list(input()) for _ in range(H)])

custom_get_bool = functools.partial(get_bool, mat, '.')
mat = mat[:, ~custom_get_bool(0)]
mat = mat[~custom_get_bool(1)]
print('\n'.join([''.join(row) for row in mat]))
