import sys
import copy
import  math
import bisect
from collections import *
from operator import itemgetter
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

li = input().split()
print('YES' if int("".join(li)) % 4 == 0 else 'NO')