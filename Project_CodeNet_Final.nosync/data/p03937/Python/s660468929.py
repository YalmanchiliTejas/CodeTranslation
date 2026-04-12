import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
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
a = [STR() for _ in range(h)]
nextstrtj = 0
for i in range(h):
    flag1 = False #.のあとに#が出たか
    flag2 = False ##が出たか
    for j in range(nextstrtj):
        if a[i][j] == '#':
            print('Impossible')
            exit()
    for j in range(nextstrtj, w):
        if flag1 and a[i][j] == '#':
            print('Impossible')
            exit()
        elif a[i][j] == '#':
            flag2 = True
            nextstrtj = j
        elif flag2 and a[i][j] == '.':
            flag1 = True
    if not flag2:
        print('Impossible')
        exit()

print('Possible')