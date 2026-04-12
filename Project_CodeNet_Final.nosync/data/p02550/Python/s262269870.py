import sys
import numpy as np
import numba
from numba import njit, b1, i4, i8, f8

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

@njit((i8, i8, i8), cache=True)
def main(N, X, M):
    A = np.empty(M + 10, np.int64)
    A[0] = X
    first = np.full(M, -1, np.int64)
    n = 0
    while True:
        n += 1
        A[n] = A[n - 1] * A[n - 1] % M
        if first[A[n]] >= 0:
            period = n - first[A[n]]
            offset = first[A[n]] + 1
            break
        first[A[n]] = n
    if N <= offset:
        return A[:N].sum()
    x = A[:offset].sum()
    N -= offset
    q, r = divmod(N, period)
    x += q * A[offset:offset + period].sum()
    x += A[offset:offset + r].sum()
    return x

N, X, M = map(int, readline().split())

print(main(N, X, M))