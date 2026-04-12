# import bisect
from collections import Counter, deque
# from copy import copy, deepcopy
# from fractions import gcd
# from functools import reduce
# from itertools import accumulate, permutations, combinations, combinations_with_replacement, groupby, product
# import math
# import numpy as np
import string
# from operator import xor
import sys

sys.setrecursionlimit(10 ** 5 + 10)


# input = sys.stdin.readline

def resolve():
    n = int(input())
    S = [list(input()) for i in range(n)]
    SS = []
    char = string.ascii_lowercase
    ans = []
    inf = 10 ** 15
    for i in S:
        SS.append(Counter(i))
    for k in range(len(char)):
        val = inf
        for j in SS:
            val = min(val, j[char[k]])
        ans.extend([char[k]] * val)

    for i in ans:
        print(i, end='')
    print()


resolve()