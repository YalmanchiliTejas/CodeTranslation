import math
from operator import itemgetter
import functools
import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = I()
s = S()
K = I()

tmp = s[K-1]

ans = ""
for i in range(N):
	if s[i] != tmp:
		ans += "*"
	else:
		ans += s[i]

print(ans)