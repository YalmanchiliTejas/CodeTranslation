# coding: utf-8
import sys
#from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
#from heapq import heappop, heappush
#from collections import defaultdict
sys.setrecursionlimit(10**7)
#import math
#from itertools import product, accumulate, combinations, product
#import bisect
#import numpy as np
#from copy import deepcopy
#from collections import deque
#from decimal import Decimal
#from numba import jit

INF = 1 << 50
EPS = 1e-8
mod = 10 ** 9 + 7


def run():
    N, *A = map(int, read().split())
    SUM = sum(A)
    ans = 0
    for a in A:
        ans += ((SUM - a) * a)%mod
        ans %= mod
        SUM -= a
    print(ans)


if __name__ == "__main__":
    run()