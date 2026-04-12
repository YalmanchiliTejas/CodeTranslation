import bisect
import heapq
import itertools
import math
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18

N = int(sys.stdin.readline())
S = sys.stdin.readline().rstrip()


def flip(c):
    return 'W' if c == 'S' else 'S'


def solve(a1, a2):
    """
    :param a1:
    :param a2:
    :rtype: str
    """
    ans = a1 + a2
    cursor = 1
    while cursor < N:
        if S[cursor] == 'o' and ans[-1] == 'S' or S[cursor] == 'x' and ans[-1] == 'W':
            ans += ans[-2]
        else:
            ans += flip(ans[-2])
        cursor += 1

    if ans[0] == ans[-1]:
        ans = ans[:-1]
        if (ans[0] == 'S' and S[0] == 'o' and ans[1] == ans[-1] or
                ans[0] == 'S' and S[0] == 'x' and ans[1] != ans[-1] or
                ans[0] == 'W' and S[0] == 'o' and ans[1] != ans[-1] or
                ans[0] == 'W' and S[0] == 'x' and ans[1] == ans[-1]):
            return ans
    return ''


# 最初の 2 個が決まれば最後まで決まる
for a1, a2 in itertools.product('SW', repeat=2):
    ret = solve(a1, a2)
    if ret:
        print(ret)
        exit()
print(-1)
