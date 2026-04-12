import sys
import re
import math
import collections
import decimal
import bisect
import itertools
import fractions
import functools
import copy
import heapq
import decimal

sys.setrecursionlimit(10000001)
INF = sys.maxsize
MOD = 10 ** 9 + 7

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===
def main():
    h, w = ns()
    mat = [list(sys.stdin.readline()) for _ in range(h)]

    total = h + w - 1
    cnt = 0
    for i in range(h):
        for j in range(w):
            if mat[i][j] == "#":
                cnt += 1

    if cnt != total:
        print("Impossible")
        exit(0)

    def dfs(x, y):
        if x == w-1 and y == h-1:
            print("Possible")
            exit(0)

        if x + 1 < w:
            if mat[y][x + 1] == "#":
                dfs(x + 1, y)
        if y + 1 < h:
            if mat[y + 1][x] == "#":
                dfs(x, y + 1)

    dfs(0, 0)
    print("Impossible")


if __name__ == '__main__':
    main()
