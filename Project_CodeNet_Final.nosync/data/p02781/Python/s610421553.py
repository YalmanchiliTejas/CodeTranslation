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

n = [int(i) for i in STR()]
k = INT()
l = len(n)
dp = [[[0, 0] for _ in range(l)] for _ in range(k + 1)] #dp[i個の0以外][j桁目まで][0:未満 1:未決定]
dp[0][0][0] = 1 #0
dp[1][0][1] = 1 #n[0]
dp[1][0][0] = n[0] - 1 #1からn[0] - 1
for j in range(1, l):
    dp[0][j][0] = dp[0][j - 1][0] #全部0

    for i in range(1, k + 1):
        dp[i][j][0] += dp[i - 1][j - 1][0] * 9 #0以外i-1個に0以外を
        dp[i][j][0] += dp[i - 1][j - 1][1] * (n[j] - 1) if n[j] > 0 else 0 #0以外i個の未満未決定にn[j]未満の数を
        dp[i][j][0] += dp[i][j - 1][0] #0以外i個かつ未満に0を
        dp[i][j][0] += dp[i][j - 1][1] if n[j] > 0 else 0 #0以外i個かつ未満未決定に0を

        dp[i][j][1] += dp[i][j - 1][1] if n[j] == 0 else 0 #0以外i個の未満未決定にn[j]を
        dp[i][j][1] += dp[i - 1][j - 1][1] if n[j] > 0 else 0 #0以外i-1個の未満未決定にn[j]を
print(sum(dp[k][l - 1]))