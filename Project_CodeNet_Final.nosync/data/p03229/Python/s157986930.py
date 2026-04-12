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
    A.sort()
    if not N % 2:
        Al = A[:N // 2]
        Ah = A[N // 2:]
        ans = 0
        ans += 2 * sum(Ah)
        ans -= Ah[0]
        ans -= 2 * sum(Al)
        ans += Al[-1]
        print(ans)

    else:
        # ans1
        Al = A[:N // 2]
        Ah = A[N // 2:]
        #print(Al, Ah)
        ans1 = 0
        ans1 += 2 * sum(Ah)
        ans1 -= sum(Ah[:2])
        ans1 -= sum(Al) * 2

        # ans2
        Al = A[:N // 2 + 1]
        Ah = A[N // 2 + 1:]
        #print(Al, Ah)
        ans2 = 0
        ans2 += 2 * sum(Ah)
        ans2 -= sum(Al) * 2
        ans2 += sum(Al[-2:])
        print(max(ans1, ans2))

if __name__ == "__main__":
    run()
