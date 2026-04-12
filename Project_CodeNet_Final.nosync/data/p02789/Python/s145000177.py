#!/usr/bin/env python3
from itertools import product, permutations, combinations
from bisect import bisect_right,bisect_left



A,B=map(int, input().split())
if A == B:
    print('Yes')
else:
    print('No')
    