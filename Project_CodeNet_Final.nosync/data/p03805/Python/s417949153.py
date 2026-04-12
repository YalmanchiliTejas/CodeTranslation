import sys
import os
import math
import bisect
import collections
import itertools
import heapq
import re
import queue
from decimal import Decimal

# import fractions

sys.setrecursionlimit(10000000)

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

lcm = lambda x, y: (x * y) // math.gcd(x, y)
# lcm = lambda x, y: (x * y) // fractions.gcd(x, y)

MOD = 10 ** 9 + 7
MAX = float('inf')


def dfs(graph, start, visited):
    visited[start] = True
    ret = 0
    if all(visited):
        visited[start] = False
        return 1

    for next in graph[start]:
        if not visited[next]:
            ret += dfs(graph, next, visited)
    visited[start] = False
    return ret


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N, M = il()
    graph = {n: [] for n in range(N)}
    visited = [False] * N
    for _ in range(M):
        a, b = il()
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    print(dfs(graph, 0, visited))


if __name__ == '__main__':
    main()
