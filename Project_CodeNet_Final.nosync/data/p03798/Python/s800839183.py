from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from functools import reduce


sys.setrecursionlimit(2147483647)
INF = 10 ** 18
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007

n = I()
s = S()
L = [0] * n


# 0が狼、1が羊
def main():
    for i, j in [(1, 0), (0, 1), (0, 0), (1, 1)]:
        L[0] = i
        L[1] = j
        for k in range(1, n - 1):
            if (s[k] == 'o' and L[k]) or (s[k] == 'x' and not L[k]):
                L[k + 1] = L[k - 1]
            else:
                L[k + 1] = L[k - 1] ^ 1

        if (s[n - 1] == 'o' and L[n - 1]) or (s[n - 1] == 'x' and not L[n - 1]):
            first = L[n - 2]
        else:
            first = L[n - 2] ^ 1
        if (s[0] == 'o' and L[0]) or (s[0] == 'x' and not L[0]):
            second = L[n - 1]
        else:
            second = L[n - 1] ^ 1
        if first == L[0] and second == L[1]:
            return L


L = main()
if L:
    print(''.join(['S' if i else 'W' for i in L]))
else:
    print(-1)