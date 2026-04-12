#!/usr/bin/env python3

import math, itertools, operator
from math import *
from math import factorial as fact
from functools import reduce
from statistics import mean, median, median_low, median_high, mode
# Before Python 3.5
from fractions import gcd
#import numpy
#import scipy, scipy.special
#from sympy import isprime, nextprime
#from sympy.ntheory import factorint

inf = float('inf')

def lcm(a, b):
    return a * b // gcd(a,b)

def perm(a, b):
    import scipy.special
    return scipy.special.perm(a, b, exact = True)

def comb(a, b):
    import scipy.special
    return scipy.special.comb(a, b, exact = True)

def dfact(n):
    import scipy.special
    return scipy.special.factorial2(n, exact = True)

def prod(l):
    return reduce(operator.mul, l)

def input_ints(inp = input, sep = ' ', conv = int):
    return map(conv, inp().split(sep = sep))

################################################################################

N = input_ints()
H = input_ints()

curmax = -inf
cnt = 0
for Hi in H:
    if curmax <= Hi:
        cnt += 1
        curmax = Hi
print(cnt)
