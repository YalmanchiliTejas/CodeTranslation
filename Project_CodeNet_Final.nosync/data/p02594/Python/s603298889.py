import sys
import numpy as np
import numba  # noqa
from numba import njit, b1, i4, i8, f8  # noqa

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def main(T):
    if T >= 30:
        return "Yes"
    else:
        return "No"


T = int(readline())

print(main(T))
