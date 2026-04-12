import sys
from collections import defaultdict as dd
from itertools import permutations as permi
input = sys.stdin.readline
N, M = map(int, input().split())
e = dd(list)
for _ in range(M):
  u, v = map(int, input().split())
  e[u].append(v)
  e[v].append(u)
res = 0
for p in permi([x for x in range(1, N + 1)], N):
  if p[0] != 1: continue
  go = list(p[: : -1])
  s = [go.pop()]
  while len(s):
    x = s.pop()
    if len(go) == 0: break
    for y in e[x]:
      if y == go[-1]:
        s.append(go.pop())
        break
  res += len(go) == 0

print(res)