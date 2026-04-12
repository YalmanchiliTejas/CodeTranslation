def b_grid_compression():
    import numpy as np
    H, W = [int(i) for i in input().split()]
    A = np.array([list(input()) for _ in range(H)])

    for i in (1, -1):
        A = A[np.any(A == '#', axis=1), :]
        A = np.rot90(A, i)
    return '\n'.join([''.join(row) for row in A])

print(b_grid_compression())