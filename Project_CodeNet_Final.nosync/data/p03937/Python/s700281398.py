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
d = [[1, 0], [0, 1]]
while y < h - 1 or x < w - 1:
    flag = [False, False]
    for i in range(2):
        if x + d[i][0] < w and y + d[i][1] < h and a[y + d[i][1]][x + d[i][0]] == 1:
            flag[i] = True
    if (flag[0] and flag[1]) or (not flag[0] and not flag[1]):
        print('Impossible')
        exit()
    if flag[0]:
        x += 1
    else:
        y += 1
print('Possible')