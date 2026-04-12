#!/usr/bin/env python3
import collections
import itertools as it
import math
#import numpy as np
 
n  = int(input())
#  = int(input())
x  = list(map(int, input().split()))
#  = list(map(int, input().split()))
#  = [int(input()) for i in range(N)]
#
# c = collections.Counter()

xsort = sorted(x)
l = xsort[n // 2 - 1]
r = xsort[n // 2]

for x_ in x:
    print(r if x_ <= l else l)
