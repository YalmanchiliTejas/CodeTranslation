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
    N, K = map(int, sysread().split())
    ans = 0
    for b in range(K+1, N+1):
        if K == 0:
            ans -= 1
        count = b-1 -K + 1
        alpha = (N-b+1) % b
        prim_add = (N-b+1) // b + 1
        prim = b-1 - alpha + 1
        if count <= prim:
            ans += count * prim_add
            continue
        ans += prim * prim_add
        L = (count - prim) // b
        resid = (count - prim) % b
        ans += ((prim_add + 1 + (L+prim_add)) * L // 2) * b
        ans += (L+ prim_add + 1) * resid

    print(ans)
if __name__ == "__main__":
    run()
