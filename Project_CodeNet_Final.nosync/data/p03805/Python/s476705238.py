import sys
from bisect import *
from collections import *
from copy import deepcopy
from heapq import *
from itertools import *
from math import *
from operator import *
from pprint import *

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

N,M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def dfs(i, visited):
    if all(visited):
        return 1
    total = 0
    for ni in graph[i]:
        if not visited[ni]:
            nvisited = visited[:]
            nvisited[ni] = True
            total += dfs(ni,nvisited)
    return total


def main():
    """ main """
    visited = [False]*N
    visited[0] = True
    print(dfs(0, visited))

if __name__ == '__main__':
    main()