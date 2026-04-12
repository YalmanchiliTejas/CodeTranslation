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

n = INT()
count = [inf for _ in range(26)]
for _ in range(n):
    s = list(STR())
    ss = Counter(s)
    for i in range(26):
        ch = chr(ord('a') + i)
        count[i] = min(count[i], ss[ch])
ans = ''
for i in range(26):
    ans += chr(i + ord('a')) * count[i]
print(ans)