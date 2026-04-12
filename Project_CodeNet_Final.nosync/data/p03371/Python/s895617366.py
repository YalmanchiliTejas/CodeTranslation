#!/usr/bin/python3

from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
INF = float("inf")
YES, Yes, yes, NO, No, no = "YES", "Yes", "yes", "NO", "No", "no"
dy4, dx4 = [0, 1, 0, -1], [1, 0, -1, 0]


def inside(y, x, H, W):
    return 0 <= y < H and 0 <= x < W

def main():
    A, B, C, X, Y = map(int, input().split())
    
    ans = INF
    for c in range(0, max(X, Y) * 2 + 1, 2):
        p = c * C
        p += max(0, A * (X - (c // 2)))
        p += max(0, B * (Y - (c // 2)))
        ans = min(ans, p)
    print(ans)

if __name__ == '__main__':
    main()
