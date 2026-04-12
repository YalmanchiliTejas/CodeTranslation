import math
import itertools
import fractions
import heapq
import collections
import bisect
import sys
import copy

sys.setrecursionlimit(10**9)
mod = 10**7+9
inf = 10**20


s = input()
if len(set(list(s)))==2:
    print("Yes")
else:
    print("No")
    