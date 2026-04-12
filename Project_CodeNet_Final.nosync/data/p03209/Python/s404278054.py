import sys, re, os
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, acos, atan, asin, log, log10
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
def debug(*args):
    if debugmode:
        print(*args)
def input(): return sys.stdin.readline().strip()
def STR(): return input()
def INT(): return int(input())
def FLOAT(): return float(input())
def MAP(): return map(int, input().split())
def S_MAP(): return map(str, input().split())
def LIST(): return list(map(int, input().split()))
def S_LIST(): return list(map(str, input().split()))
def lcm(a, b): return a * b // gcd(a, b)
sys.setrecursionlimit(10 ** 9)
inf = sys.maxsize
mod = 10 ** 9 + 7
dx = [0, 0, 1, -1, 1, -1, -1, 1]
dy = [1, -1, 0, 0, 1, -1, 1, -1]
debugmode = False

def func(level, x):
    debug(level, x)
    if level == 0 and x == 1:
        return 1
    elif level == 0 and x <= 0:
        return 0
    npast = num[level - 1]
    if x <= npast + 1:
        tmp = func(level - 1, x - 1)
        debug('a', level, x, tmp)
        return tmp
    elif x == npast + 2:
        tmp = func(level - 1, x - 2)
        debug('b', level, x, tmp + 1)
        return tmp + 1
    else:
        tmp1  = num2[level - 1]
        debug('tmp1', tmp1)
        if x == npast * 2 + 3:
            debug('aa', x - npast - 3)
            tmp2 = func(level - 1, x - npast - 3)
        else:
            tmp2 = func(level - 1, x - npast - 2)
        debug('c', level, x, tmp1 + 1 + tmp2)
        return tmp1 + 1 + tmp2

n, x = MAP()
num = [1]
for i in range(2, n + 1):
    num.append(2 * num[-1] + 3)
num2 = [1]
for i in range(2, n + 1):
    num2.append(2 * num2[-1] + 1)
debug(num)
debug(num2)
ans = func(n, x)
print(ans)
