import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
MOD = 10**9+7

c = input()
if c == "a" or c == "e" or c == "i" or c == "o" or c == "u":
    print("vowel")
else:
    print("consonant")