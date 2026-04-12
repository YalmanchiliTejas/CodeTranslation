import math
import string
import collections
from collections import Counter
from collections import deque
from decimal import Decimal
import sys
import fractions


def readints():
    return list(map(int, input().split()))


def nCr(n, r):
    return math.factorial(n)//(math.factorial(n-r)*math.factorial(r))


def has_duplicates2(seq):
    seen = []
    for item in seq:
        if not(item in seen):
            seen.append(item)
    return len(seq) != len(seen)


def divisor(n):
    divisor = []
    for i in range(1, n+1):
        if n % i == 0:
            divisor.append(i)
    return divisor


# coordinates
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
a, b, c, x, y = map(int, input().split())
#print(a, b, c, x, y)
ab = math.floor((x+y)/2)
#print('ab', ab)
p1 = a*x+b*y
max_x = max(x, y)
p2 = c*max_x+c*max_x
min_x = min(x, y)
p3 = a*(x-min_x)+b*(y-min_x)+c*((min_x)*2)
ans = min(p1, p2, p3)
print(ans)
