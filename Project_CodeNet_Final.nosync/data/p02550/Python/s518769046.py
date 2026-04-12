import sys
import re
import random
import math
import copy
from heapq import heappush, heappop, heapify
from functools import cmp_to_key
from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, Counter
# sys.setrecursionlimit(1000000)

# input aliases
input = sys.stdin.readline
getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]

INF = float("inf")
MOD = 10**9 + 7
divide = lambda x: pow(x, MOD-2, MOD)


def solve():
    n, x, m = getList()

    visited = [-1] * (m+1)
    acc = [-1] * (m+1)
    tmp = x
    tmpsum = 0
    index = 0
    while True:
        # print(tmp)
        if visited[tmp] >= 0:
            cycle = index - visited[tmp]
            issyu = tmpsum - acc[tmp]
            outofcycle = index - 1
            ans = tmpsum
            cyclestart = tmp
            break

        visited[tmp] = index
        acc[tmp] = tmpsum
        tmpsum += tmp
        tmp = (tmp ** 2) % m
        index += 1
        if index == n:
            print(tmpsum)
            return

    # print("cycle ", cycle, issyu, cyclestart, outofcycle, ans)
    ans += ((n - outofcycle - 1) // cycle) * issyu


    tmp = cyclestart
    for i in range((n - outofcycle - 1) % cycle):
        ans += tmp
        tmp = (tmp ** 2) % m

    print(ans)
    # 16243 over




def main():
    n = getN()
    for _ in range(n):
        solve()

    return
if __name__ == "__main__":
    # main()
    solve()