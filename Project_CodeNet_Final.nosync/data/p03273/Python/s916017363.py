import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, acos, atan, asin
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
def input(): return sys.stdin.readline().strip()
def STR(): return input()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))
sys.setrecursionlimit(10 ** 9)
inf = sys.maxsize
mod = 10 ** 9 + 7

h, w = MAP()
a = [list(STR()) for _ in range(h)]
i = 0
while i < len(a):
    if set(a[i]) == set(['.']):
        del a[i]
    else:
        i += 1
j = 0
while j < len(a[0]):
    arr = [a[i][j] for i in range(len(a))]
    if set(arr) == set(['.']):
        for i in range(len(a)):
            del a[i][j]
    else:
        j += 1
for i in range(len(a)):
    print(''.join(a[i]))
