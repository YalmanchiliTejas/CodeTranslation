import bisect
import math
import sys
from collections import Counter, defaultdict, deque
from copy import copy, deepcopy
from heapq import heapify, heappop, heappush
from itertools import combinations, permutations
from queue import Queue

read = sys.stdin.read
readline = sys.stdin.readline 
readlines = sys.stdin.readlines 

inf = float("inf")


def main():
    A, B, C, X, Y = map(int, input().split())
    if A + B > 2 * C:
        if X > Y:
            ret = 2 * C * Y
            if A > 2 * C:
                ret += 2 * C * (X - Y)
            else:
                ret += A * (X - Y)
        else:
            ret = 2 * C * X
            if B > 2 * C:
                ret += 2 * C * (Y - X)
            else:
                ret += B * (Y - X)
    else:
        ret = A * X + B * Y
    print(ret)
        
      
if __name__=='__main__':
    main()