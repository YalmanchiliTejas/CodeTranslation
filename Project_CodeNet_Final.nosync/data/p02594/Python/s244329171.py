import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy
INF = 10**18


if __name__ == "__main__":
    x = int(input())
    if x>=30:
        print("Yes")
    else:
        print("No")