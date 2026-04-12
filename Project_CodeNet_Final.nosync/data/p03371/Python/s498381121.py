import sys, math
def input():
    return sys.stdin.readline()[:-1]
from itertools import permutations, combinations
from collections import defaultdict, Counter
from math import factorial
from bisect import bisect_left # bisect_left(list, value)
#from fractions import gcd

sys.setrecursionlimit(10**7)
A, B, C, X, Y = map(int, input().split())

val1 = A*X + B*Y
minXY = min(X, Y)
val2 = C*2*minXY + A*(X-minXY) + B*(Y-minXY)
maxXY = max(X, Y)
val3 = C*2*maxXY

print(min(val1, val2, val3))
