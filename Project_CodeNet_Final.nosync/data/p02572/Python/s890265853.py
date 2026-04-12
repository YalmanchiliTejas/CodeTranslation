import sys
import re
from math import ceil, floor, sqrt, pi, factorial, gcd
from copy import deepcopy
from collections import Counter, deque
from heapq import heapify, heappop, heappush
from itertools import accumulate, product, combinations, combinations_with_replacement
from bisect import bisect, bisect_left, bisect_right
from functools import reduce
from decimal import Decimal, getcontext
# input = sys.stdin.readline
def i_input(): return int(input())
def i_map(): return map(int, input().split())
def i_list(): return list(i_map())
def i_row(N): return [i_input() for _ in range(N)]
def i_row_list(N): return [i_list() for _ in range(N)]
def s_input(): return input()
def s_map(): return input().split()
def s_list(): return list(s_map())
def s_row(N): return [s_input for _ in range(N)]
def s_row_str(N): return [s_list() for _ in range(N)]
def s_row_list(N): return [list(s_input()) for _ in range(N)]
def lcm(a, b): return a * b // gcd(a, b)
sys.setrecursionlimit(10 ** 6)
INF = float('inf')
MOD = 10 ** 9 + 7
num_list = []
str_list = []


def main():
    N = i_input()
    A = list(i_map())

    mod1 = 0
    for i in range(0,N):
        mod1 = (mod1+A[i]%MOD)%MOD
    
    mod1 = (mod1 * mod1)%MOD

    mod2 = 0
    for i in range(0,N):
        mod2 = (mod2+((A[i]*A[i])%MOD)%MOD)

    mod = (mod1-mod2)%MOD
    
    answer = ((500000004 * mod))% MOD

    print(answer)
    
    return

if __name__ == '__main__':
    main()