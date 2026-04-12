#! /usr/bin/env python3

from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, combinations_with_replacement

S = input()

if S[0] == S[1] == S[2]:
    print("No")
    exit()
print("Yes")