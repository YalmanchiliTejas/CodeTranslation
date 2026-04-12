from itertools import accumulate, permutations, combinations, product, combinations_with_replacement, groupby
from math import sqrt, factorial, log
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heappushpop
import sys
stdin = sys.stdin
mod = 10**9 + 7

def ns(): return stdin.readline().rstrip()
def ni(): return int(ns())
def na(): return list(map(int, stdin.readline().split()))

s = ns()

if "A" in s and "B" in s:
    print("Yes")
else:
    print("No")