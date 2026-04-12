import sys
from fractions import gcd
from itertools import groupby as gb
from itertools import permutations as perm
from itertools import combinations as comb
from collections import Counter as C
from collections import defaultdict as dd
sys.setrecursionlimit(10**5)
def y(f):
    if f:
        print('Yes')
    else:
        print('No')
def Y(f):
    if f:
        print('YES')
    else:
        print('NO')
def Z(f):
    if f:
        print('Yay!')
    else:
        print(':(')
def ispow(n):
    if int(n**.5)**2==n:
        return True
    return False

s = input()
y(s != s[0] * 3)

