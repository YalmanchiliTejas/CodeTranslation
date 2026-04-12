import sys, math
def input():
    return sys.stdin.readline()[:-1]
from itertools import permutations, combinations
from collections import defaultdict, Counter
from math import factorial
from bisect import bisect_left # bisect_left(list, value)
#from fractions import gcd
enu = enumerate

sys.setrecursionlimit(10**7)
S = input()

if S == 'AAA' or S=='BBB':
    print('No')
else:
    print('Yes')
