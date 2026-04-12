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
a = [[1 if i == '#' else 0 for i in STR()] for _ in range(h)]
s = 0
for i in range(h):
    s += sum(a[i])
if s != h + w - 1:
    print('Impossible')
    exit()
y = 0
x = 0
while y < h - 1 or x < w - 1:
    flag1 = False
    flag2 = False
    if y + 1 < h and a[y + 1][x] == 1:
        flag1 = True
    if x + 1 < w and a[y][x + 1] == 1:
        flag2 = True
    if (flag1 and flag2) or (not flag1 and not flag2):
        print('Impossible')
        exit()
    if flag1:
        y += 1
    if flag2:
        x += 1
print('Possible')
