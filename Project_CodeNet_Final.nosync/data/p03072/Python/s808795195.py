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
a = list(map(int, input().split()))

mx = 0
count = 0
for i in a:
    if i >= mx:
        count += 1
        mx = max(i, mx)
print(count)


