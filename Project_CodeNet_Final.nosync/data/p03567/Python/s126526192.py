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

readl= lambda: list(map(int, sys.stdin.readline().split()))
readt= lambda: tuple(map(int, sys.stdin.readline().split()))
read = lambda: sys.stdin.readline().rstrip()
readi = lambda: int(read())
readmi = lambda: map(int, sys.stdin.readline().split())
readms = lambda: map(str, sys.stdin.readline().split())

s = read()
if 'AC' in s:
    print('Yes')
else:
    print('No')