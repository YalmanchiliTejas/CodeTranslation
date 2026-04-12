import sys
sys.setrecursionlimit(10000000)
def input():
    return sys.stdin.readline()[:-1]
from bisect import *
from collections import *
from heapq import *
from fractions import Fraction

n = int(input())
S = input()
x = S[int(input())-1]
ans = ''
for c in S:
    if c != x:
        ans += '*'
    else:
        ans += x
print(ans)
