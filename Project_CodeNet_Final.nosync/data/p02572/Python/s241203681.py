import sys
import math
import collections
import decimal
import itertools
from collections import deque
from functools import reduce
import heapq
import copy
import numpy as np
n = int(input())
#d, t, s = map(int, sys.stdin.readline().split())
#s = input()
a = list(map(int, sys.stdin.readline().split()))

mod = 10 ** 9 + 7

sumlist= sum(a)
x = []
for i in range(n):
    x.append(sumlist - a[i])
    sumlist -= a[i]

ans = 0
for i in range(n):
    ans += (a[i] * x[i])
    ans %= mod

print(ans)



