import sys
import  math
from statistics import *
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

x, y, z = na()
if x - (x//(y+z)) * (y+z) >= z:
    print(x//(y+z))
else:
    print(x//(y+z)-1)