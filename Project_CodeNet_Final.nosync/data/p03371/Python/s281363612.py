from __future__ import print_function

import sys

import re
import array
import copy
import functools
import operator

import math
import string
import fractions
from fractions import Fraction
from fractions import gcd
# fractions.gcd() を用いること
# math.log2()はatcoderでは対応していない．留意せよ．

import collections
import itertools
import bisect

import random
import time

import heapq
from heapq import heappush
from heapq import heappop
from heapq import heappushpop
from heapq import heapify
from heapq import heapreplace
from queue import PriorityQueue as pq
from queue import Queue

from itertools import accumulate

from collections import deque
from collections import Counter

from operator import mul
from functools import reduce

input = sys.stdin.readline


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    return


def lcm(n, m):
    return int(n * m / gcd(n, m))


def coprimize(p, q):
    common = fractions.gcd(p, q)
    return (p // common, q // common)


def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom


def find_gcd(list_l):
    x = reduce(gcd, list_l)
    return x


def main():
    a, b, c, x, y = map(int, input().strip().split())
    t1=a*x + b*y
    t2=c * 2 * min(x, y) + (a if x > y else b)*(max(x, y) - min(x, y))
    t3=c * 2 * max(x, y)
    print(min(t1,t2,t3))

if __name__ == '__main__':
    main()
