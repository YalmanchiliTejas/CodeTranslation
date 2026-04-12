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
li = [Counter(input()) for _ in range(n)]
d = dict(li[0])
for c in li:
    li = []
    for k, v in d.items():
        if k not in c.keys():
            li.append(k)
        else:
            d[k] = min(d[k], c[k])
    for k in li:
        del d[k]
if len(c) == 0:
    print()
else:
    d = sorted(d.items(), key=itemgetter(0))
    ans = ""
    for k, v in d:
        ans += k * v
    print(ans)