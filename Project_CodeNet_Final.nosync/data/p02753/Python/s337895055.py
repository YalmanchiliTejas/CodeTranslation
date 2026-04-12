import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
from bisect import *
from collections import *
from heapq import *
INF = 500000
mod = 10**9+7

S = input()
if 'A' in S and 'B' in S:
    print('Yes')
else:
    print('No')
