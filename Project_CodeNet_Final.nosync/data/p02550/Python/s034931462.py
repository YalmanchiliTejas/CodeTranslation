# coding: utf-8
import sys

# from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
printout = sys.stdout.write
sprint = sys.stdout.flush
# from heapq import heappop, heappush
# from collections import defaultdict
sys.setrecursionlimit(10 ** 7)
# import math
# from itertools import product, accumulate, combinations, product
# import bisect
# import numpy as np
# from copy import deepcopy
#from collections import deque
# from decimal import Decimal
# from numba import jit

INF = 1 << 50
EPS = 1e-8
mod = 998244353


def intread():
    return int(sysread())
def mapline(t=int):
    return map(t, sysread().split())
def mapread(t=int):
    return map(t, read().split())

def next_val(An, M):
    return (An * An) % M

def run():
    N, X, M = mapline()
    arr = [X]
    valset = {}
    valset[X] = 0
    while True:
        an = arr[-1]
        next_a = next_val(an, M)
        if not next_a in valset.keys():
            arr.append(next_a)
            valset[next_a] = len(arr) - 1
        else:
            break
    idx1 = valset[next_a]
    K = len(arr)
    ans = 0
    if N > idx1:
        ans += sum(arr[:idx1])
    else:
        ans += sum(arr[:N])
        print(ans)
        return

    N -= idx1
    l = K - idx1
    sums = sum(arr[idx1:])
    cycle = N // l
    ans += sums * cycle
    N %= l
    ans += sum(arr[idx1:idx1+N])
    print(ans)






if __name__ == "__main__":
    run()
