import sys
import collections
import itertools
import math
import re
from collections import deque

MOD = 10 ** 9 + 7

N, X = [int(x) for x in input().split()]
ML = 51
P = [0] * ML
A = [0] * ML

P[0] = 1
A[0] = 1

for i in range(1, ML):
    P[i] = 2 * P[i - 1] + 1
    A[i] = 2 * A[i - 1] + 3


def f(n, x):
    if x <= 0:
        return 0
    if n == 0:
        return 1

    r = 0
    if x <= 1 + A[n - 1]:
        r = f(n - 1, x - 1)
    elif x == 2 + A[n - 1]:
        r = 1 + P[n - 1]
    else:
        r = f(n - 1, x - 2 - A[n - 1]) + 1 + P[n - 1]

    return r


r = f(N, X)

print(r)
