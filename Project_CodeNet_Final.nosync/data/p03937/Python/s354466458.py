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
a = [input() for _ in range(h)]
y = 0
x = 0
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
while y < h and x < w:
    flag = [False for _ in range(4)]
    for i in range(4):
        if 0 <= y + dy[i] < h and 0 <= x + dx[i] < w and a[y + dy[i]][x + dx[i]] == '#':
            flag[i] = True
    if x == y == 0:
        flag[2] = True
    if x == w - 1 and y == h - 1:
        flag[0] = True
    if flag[0]:
        y += 1
    else:
        x += 1
    if not len(set(flag[0:2])) == len(set(flag[2:4])) == 2:
        print('Impossible')
        exit()
print('Possible')
