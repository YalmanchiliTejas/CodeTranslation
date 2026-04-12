import sys
import copy
import string
import  math
from _bisect import *
from collections import *
from operator import itemgetter
from math import factorial
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
print(n * 800 - n // 15 * 200)