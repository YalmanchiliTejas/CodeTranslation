# import numpy as np
# import math
# import copy
# from collections import deque
import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10000)


def dfs(now,N,sides,visited):

    all_visited = True

    if False in visited:
        all_visited = False

    if all_visited:
        return 1

    res = 0

    for i in range(N):
        if not sides[now][i]:
            continue
        if visited[i]:
            continue
        visited[i] = True
        res += dfs(i,N,sides,visited)
        visited[i] = False

    return res


def main():
    N,M = map(int,input().split())

    sides = [[False for j in range(N)] for i in range(N)]

    for i in range(M):
        A,B = map(int,input().split())
        sides[A-1][B-1] = sides[B-1][A-1] = True

    visited = [False for i in range(N)]
    visited[0] = True

    res = dfs(0,N,sides,visited)

    print(res)



main()
