import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
from bisect import bisect
from heapq import heappush, heappop

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

n = INT()
S = [input() for _ in range(n)]

dic = defaultdict(lambda: INF)
set_char = set()
for s in S:
	set_char |= set(s)
for s in S:
	cnt_s = Counter(s)
	for char in set_char:
		dic[char] = min(dic[char], cnt_s[char])

ans = ""
for x in sorted(dic.keys()):
	if dic[x] != 0:
		ans += x*dic[x]
print(ans)
