from collections import defaultdict, Counter, namedtuple, deque
import itertools
import functools
import bisect
import heapq
import math
from fractions import gcd

NN = 202020
MOD = 10**9+7
INF = float("inf")

n, m = map(int, input().split())
Edge = [list(map(int, input().split())) for i in range(m)]
graph = [set() for _ in range(n)]

for e in Edge:
    graph[e[0]-1].add(e[1]-1)
    graph[e[1]-1].add(e[0]-1)


def next_node(idx, A):
    if idx == n-1:
        return True
    if A[idx+1] in graph[A[idx]]:
        return next_node(idx+1, A)
    else:
        return False


count = 0
for li in itertools.permutations([i+1 for i in range(n-1)]):
    count += next_node(0, [0]+list(li))
    # if next_node(0, [0]+list(li)):
    #     print([0]+list(li))

print(count)
