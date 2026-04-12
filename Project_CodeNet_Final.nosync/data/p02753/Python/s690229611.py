import itertools
import math
import sys
import heapq
from collections import Counter
from collections import deque
from fractions import gcd
from functools import reduce
sys.setrecursionlimit(4100000)
from functools import lru_cache
INF = 1 << 60

#ここから書き始める
s = input()
s_set = set(s)
if len(s_set) == 1:
    print("No")
else:
    print("Yes")
