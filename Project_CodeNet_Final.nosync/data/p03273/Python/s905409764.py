from __future__ import print_function
# import numpy as np
# import numpypy as np
import sys
input = sys.stdin.readline

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    return

import math
import string
import fractions
from fractions import Fraction
from fractions import gcd

def lcm(n,m):
    return int(n*m/gcd(n,m))

import re
import array
import copy
import functools
import operator

import collections
import itertools
import bisect
import heapq


from heapq import heappush
from heapq import heappop
from heapq import heappushpop
from heapq import heapify
from heapq import heapreplace

from queue import PriorityQueue as pq

def reduce(p, q):
    common = fractions.gcd(p, q)
    return (p//common , q//common )
# from itertools import accumulate
# from collections import deque

from operator import mul
from functools import reduce

def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom

import random


def main():
    h,w = map(int, input().strip().split())
    g = [input().strip() for _ in range(h)]
    gg  = [col for col in zip(*g) if("#" in col)]
    
    eprint("gg ",end=": \n")
    eprint(gg)
    for elem in gg:
        eprint(elem)
        
    gg = [row for row in zip(*gg) if("#" in row)]
    eprint("gg ",end=": \n")
    eprint(gg)
    # for elem in gg:
    #     eprint(elem)
    
    for S in gg:
        print("".join(S))
    return

if __name__ == '__main__':
    main()


# trA  = [list(col) for col in zip(*A)]
