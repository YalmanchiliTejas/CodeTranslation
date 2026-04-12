# Date [ 2020-09-19 21:46:14 ]
# Problem [ e.py ]
# Author Koki_tkg

import sys
# import math
# import bisect
# import numpy as np
# from decimal import Decimal
# from numba import njit, i8, u1, b1 #JIT compiler
# from itertools import combinations, product
# from collections import Counter, deque, defaultdict

# sys.setrecursionlimit(10 ** 6)
MOD = 10 ** 9 + 7
INF = 10 ** 9
PI = 3.14159265358979323846

def read_str():      return sys.stdin.readline().strip()
def read_int():      return int(sys.stdin.readline().strip())
def read_ints():     return map(int, sys.stdin.readline().strip().split())
def read_ints2(x):   return map(lambda num: int(num) - x, sys.stdin.readline().strip().split())
def read_str_list(): return list(sys.stdin.readline().strip().split())
def read_int_list(): return list(map(int, sys.stdin.readline().strip().split()))
def GCD(a: int, b: int) -> int: return b if a%b==0 else GCD(b, a%b)
def LCM(a: int, b: int) -> int: return (a * b) // GCD(a, b)

def Main():
    n, x, m = read_ints()
    query = []
    s = set([])
    while x not in s:
        s.add(x)
        query.append(x)
        x = x * x % m
    
    frm = query.index(x)
    length = len(query) - frm
    total = sum(query[frm:])
    
    ans = sum(query[:frm]) + total * ((n - frm) // length) + sum(query[frm:frm + (n - frm) % length])
    print(ans)

if __name__ == '__main__':
    Main()