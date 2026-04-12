import bisect
import copy
import fractions
import math
import numpy as np
from collections import Counter, deque
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product


def resolve():
    h, w = map(int, input().split())
    A = [[_ for _ in input()] for _ in range(h)]
    B = [i for i in A if '#' in i]
    C = zip(*[i for i in zip(*B) if '#' in i])
    
    for i in C:
        print(*i, sep='')


resolve()