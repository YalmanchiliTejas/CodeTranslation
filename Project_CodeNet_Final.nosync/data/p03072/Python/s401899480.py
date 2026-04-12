import sys
from bisect import *
from heapq import *
from collections import *
from itertools import *
from functools import *
from math import *
from fractions import *

sys.setrecursionlimit(100000000)
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
H = list(map(int, input().split()))

print(sum(1 for i in range(N) if i == 0 or max(H[:i]) <= H[i]))

