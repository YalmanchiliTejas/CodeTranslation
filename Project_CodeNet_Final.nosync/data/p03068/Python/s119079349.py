# coding: UTF-8
import sys
#sys.setrecursionlimit(n)
import heapq
import re
import bisect
import random
import math
import itertools
from collections import defaultdict, deque
from copy import deepcopy
from decimal import *

n = int(input())
a = input()
a = list(a)
k = int(input())

c = a[k - 1]
s = ''
for i in a:
    if i == c:
        s += i
    else:
        s += '*'
print(s)
