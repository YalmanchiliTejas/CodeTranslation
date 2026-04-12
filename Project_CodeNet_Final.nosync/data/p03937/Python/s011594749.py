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

def func(y, x, cnt):
    if y == h - 1 and x == w - 1:
        cnt += 1
        return y, x, cnt
    if y < h - 1 and a[y + 1][x] == 1:
        cnt += 1
        return func(y + 1, x, cnt)
    if x < w - 1 and a[y][x + 1] == 1:
        cnt += 1
        return func(y, x + 1, cnt)
    if y < h - 1 and a[y + 1][x] == 0:
        return y, x, cnt
    if x < w - 1 and a[y][x + 1] == 0:
        return y, x, cnt

h, w = MAP()
a = [[1 if i == '#' else 0 for i in STR()] for _ in range(h)]
s = 0
for i in range(h):
    s += sum(a[i])
y, x, cnt = func(0, 0, 0)
if y == h - 1 and x == w - 1 and cnt == s:
    print('Possible')
else:
    print('Impossible')
