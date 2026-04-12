from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1000000)

(N, M) = reads()

conn = [[False] * N for _ in range(N)]

for _ in range(M):
  (a, b) = reads()
  (a, b) = (a-1, b-1)
  conn[a][b] = conn[b][a] = True

count = 0

for p in permutations(range(1, N)):
  if conn[0][p[0]] and all(conn[p[i]][p[i+1]] for i in range(N-2)):
    count += 1

print(count)
