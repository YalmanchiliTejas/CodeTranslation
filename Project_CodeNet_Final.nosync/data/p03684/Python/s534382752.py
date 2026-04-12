import sys
from collections import defaultdict as dd
import heapq
input = sys.stdin.readline
N = int(input())
p = [tuple(map(int, input().split())) for _ in range(N)]
e = dd(list)
p = [(i, p[i][0], p[i][1]) for i in range(N)]
p.sort(key = lambda x: x[1])
for i in range(N - 1):
  x = p[i][0]
  y = p[i + 1][0]
  e[x].append((y, abs(p[i][1] - p[i + 1][1])))
  e[y].append((x, abs(p[i][1] - p[i + 1][1])))
p.sort(key = lambda x: x[2])
for i in range(N - 1):
  x = p[i][0]
  y = p[i + 1][0]
  e[x].append((y, abs(p[i][2] - p[i + 1][2])))
  e[y].append((x, abs(p[i][2] - p[i + 1][2])))
class prim:
  def __init__(self, n, e):
    self.e = e
    self.n = n
  def MSTcost(self):
    h = []
    visited = [0] * (self.n + 1)
    ks = list(self.e.keys())
    b = pow(10, 10)
    for edge in self.e[ks[0]]:
      heapq.heappush(h, edge[1] * b + edge[0])
    res = 0
    visited[ks[0]] = 1
    while len(h):
      p = heapq.heappop(h)
      p0 = p // b
      p1 = p % b
      if visited[p1]: continue
      visited[p1] = 1
      for q in self.e[p1]:
        if visited[q[0]]:
          continue
        heapq.heappush(h, q[1] * b + q[0])
      res += p0
    return res
pri = prim(N, e)
print(pri.MSTcost())