#!/usr/bin/env python

from collections import deque, defaultdict
import itertools as ite
import sys
import math
from decimal import *

sys.setrecursionlimit(1000000)

INF = 10 ** 18
MOD = 10 ** 9 + 7

N, M = map(int, raw_input().split())
if N == M:
    print "Yes"
else:
    print "No"