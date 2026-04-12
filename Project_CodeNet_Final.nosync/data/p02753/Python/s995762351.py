from copy import deepcopy
from sys import exit,setrecursionlimit
import math
from collections import defaultdict,Counter,deque
from fractions import Fraction as frac
import fractions
from functools import reduce
from operator import mul
import bisect
import sys
import logging
import heapq
import itertools

logging.basicConfig(level=logging.ERROR)

input = sys.stdin.readline

setrecursionlimit(1000000)


def main():
    s = input()
    if s.count('A') == 3 or s.count('B') == 3:
        print('No')
    else:
        print('Yes')

main()