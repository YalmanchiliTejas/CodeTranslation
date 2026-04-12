import numba
from numba import njit, b1, i4, i8, f8
import numpy as np  # noqa

N = int(input())
A = [int(x) for x in input().split()]


def main(A):
    ans = 0
    s = 0
    for i in range(N - 2, -1, -1):
        s += A[i + 1]
        s %= 10**9 + 7
        ans = (ans + A[i] * s) % (10**9 + 7)
    return ans


print(main(A))
